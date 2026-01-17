"""Mypy plugin for typed_envs.

This plugin teaches mypy to treat EnvironmentVariable[T] as having the methods
and attributes of both EnvironmentVariable and the underlying T (for concrete
types), even though the runtime object is a dynamic EnvironmentVariable subclass.

Enable in your mypy config:

    [mypy]
    plugins = typed_envs.mypy_plugin

This keeps runtime behavior unchanged while allowing:

    some_var = typed_envs.create_env("SOME_VAR", int, 10)
    def foo(x: int) -> None: ...
    foo(some_var)  # passes with the plugin enabled
"""

from __future__ import annotations

import hashlib
import json
from typing import Callable, Iterable

from mypy.mro import MroError, calculate_mro
from mypy.nodes import Block, ClassDef, SymbolTable, TypeInfo
from mypy.plugin import AnalyzeTypeContext, FunctionContext, MethodContext, Plugin
from mypy.types import (
    AnyType,
    CallableType,
    Instance,
    NoneType,
    Overloaded,
    Type,
    TypeOfAny,
    TypeType,
    TypeVarType,
    UnionType,
    get_proper_type,
)


_ENV_VAR_TYPES = {
    "typed_envs.EnvironmentVariable",
    "typed_envs._env_var.EnvironmentVariable",
}

_CREATE_ENV_FUNCTIONS = {
    "typed_envs.create_env",
    "typed_envs.__init__.create_env",
}
_CREATE_ENV_METHODS = {
    "typed_envs.factory.EnvVarFactory.create_env",
    "typed_envs.EnvVarFactory.create_env",
}


def _find_arg_type(
    ctx: FunctionContext | MethodContext, names: Iterable[str]
) -> Type | None:
    for name in names:
        for index, callee_name in enumerate(ctx.callee_arg_names):
            if callee_name == name and ctx.arg_types[index]:
                return ctx.arg_types[index][0]
    return None


def _class_arg_to_type(arg_type: Type) -> Type | None:
    proper = get_proper_type(arg_type)
    if isinstance(proper, TypeType):
        return proper.item
    if isinstance(proper, Instance) and proper.type.fullname == "builtins.type":
        if proper.args:
            return proper.args[0]
        return AnyType(TypeOfAny.special_form)
    if isinstance(proper, AnyType):
        return proper
    if isinstance(proper, CallableType):
        return proper.ret_type
    if isinstance(proper, Overloaded):
        items = proper.items if isinstance(proper.items, list) else proper.items()
        ret_types = [item.ret_type for item in items]
        first = ret_types[0]
        if all(ret == first for ret in ret_types[1:]):
            return first
        return UnionType.make_union(ret_types)
    if isinstance(proper, UnionType):
        items: list[Type] = []
        for item in proper.items:
            converted = _class_arg_to_type(item)
            if converted is None:
                return None
            items.append(converted)
        return UnionType.make_union(items)
    return None


def _envvar_type_key(env_arg: Type, base: Instance) -> str:
    payload = json.dumps(
        {"arg": env_arg.serialize(), "base": base.serialize()}, sort_keys=True
    )
    return hashlib.sha1(payload.encode("utf-8")).hexdigest()


def _typed_envvar_name(digest: str) -> str:
    return f"EnvironmentVariable_{digest[:10]}"


class TypedEnvsPlugin(Plugin):
    """Plugin that maps EnvironmentVariable[T] to an intersection of T and EnvironmentVariable."""

    def __init__(self, options) -> None:
        super().__init__(options)
        self._envvar_cache: dict[str, TypeInfo] = {}

    def get_function_hook(
        self, fullname: str
    ) -> Callable[[FunctionContext], Type] | None:
        if fullname in _CREATE_ENV_FUNCTIONS:
            return self._create_env_function_hook
        return None

    def get_method_hook(
        self, fullname: str
    ) -> Callable[[MethodContext], Type] | None:
        if fullname in _CREATE_ENV_METHODS:
            return self._create_env_method_hook
        return None

    def get_type_analyze_hook(
        self, fullname: str
    ) -> Callable[[AnalyzeTypeContext], Type] | None:
        if fullname in _ENV_VAR_TYPES:
            return self._env_var_type_analyze
        return None

    def _env_var_type_analyze(self, ctx: AnalyzeTypeContext) -> Type:
        if len(ctx.type.args) != 1:
            return AnyType(TypeOfAny.special_form)
        analyzed = ctx.api.analyze_type(ctx.type.args[0])
        result = self._envvar_intersection(ctx.api, analyzed)
        if ctx.type.optional:
            return UnionType.make_union([result, NoneType()])
        return result

    def _envvar_intersection(self, api, arg: Type) -> Type:
        proper = get_proper_type(arg)
        if isinstance(proper, AnyType):
            return proper
        if isinstance(proper, UnionType):
            items = [self._envvar_intersection(api, item) for item in proper.items]
            return UnionType.make_union(items)
        if isinstance(proper, TypeVarType):
            if proper.values:
                items = [self._envvar_intersection(api, item) for item in proper.values]
                return UnionType.make_union(items)
            bound = get_proper_type(proper.upper_bound)
            if isinstance(bound, Instance):
                return self._build_envvar_instance(api, proper, bound)
            return self._named_type(api, "typed_envs._env_var.EnvironmentVariable", [proper])
        if isinstance(proper, TypeType):
            proper = get_proper_type(proper.item)
        if isinstance(proper, Instance):
            return self._build_envvar_instance(api, proper, proper)
        return self._named_type(api, "typed_envs._env_var.EnvironmentVariable", [proper])

    def _build_envvar_instance(
        self,
        api,
        env_arg: Type,
        base: Instance,
        env_var_instance: Instance | None = None,
    ) -> Instance:
        if env_var_instance is None:
            env_var_instance = self._named_type(
                api, "typed_envs._env_var.EnvironmentVariable", [env_arg]
            )
        key = _envvar_type_key(env_arg, base)
        info = self._envvar_cache.get(key)
        if info is None:
            class_name = _typed_envvar_name(key)
            defn = ClassDef(class_name, Block([]))
            defn.fullname = f"typed_envs.mypy_plugin.{class_name}"
            info = TypeInfo(SymbolTable(), defn, "typed_envs.mypy_plugin")
            defn.info = info
            info.bases = [env_var_instance, base]
            try:
                calculate_mro(
                    info, obj_type=lambda: self._named_type(api, "builtins.object", [])
                )
            except MroError:
                obj_type = self._named_type(api, "builtins.object", []).type
                info.mro = [info, env_var_instance.type, base.type, obj_type]
            self._envvar_cache[key] = info
        return Instance(info, [])

    def _named_type(self, api, fullname: str, args: list[Type]) -> Instance:
        if hasattr(api, "named_generic_type"):
            return api.named_generic_type(fullname, args)
        return api.named_type(fullname, args)

    def _extract_envvar_instance(self, typ: Type) -> Instance | None:
        proper = get_proper_type(typ)
        if not isinstance(proper, Instance):
            return None
        if proper.type.fullname in _ENV_VAR_TYPES:
            return proper
        for base in proper.type.bases:
            if base.type.fullname in _ENV_VAR_TYPES:
                return base
        return None

    def _create_env_function_hook(self, ctx: FunctionContext) -> Type:
        arg_type = _find_arg_type(ctx, ("typ",))
        if arg_type is None:
            return ctx.default_return_type
        type_arg = _class_arg_to_type(arg_type)
        if type_arg is None:
            return ctx.default_return_type
        env_var_instance = self._extract_envvar_instance(ctx.default_return_type)
        if isinstance(type_arg, Instance):
            return self._build_envvar_instance(
                ctx.api,
                type_arg,
                type_arg,
                env_var_instance,
            )
        return self._envvar_intersection(ctx.api, type_arg)

    def _create_env_method_hook(self, ctx: MethodContext) -> Type:
        arg_type = _find_arg_type(ctx, ("env_var_type",))
        if arg_type is None:
            return ctx.default_return_type
        type_arg = _class_arg_to_type(arg_type)
        if type_arg is None:
            return ctx.default_return_type
        env_var_instance = self._extract_envvar_instance(ctx.default_return_type)
        if isinstance(type_arg, Instance):
            return self._build_envvar_instance(
                ctx.api,
                type_arg,
                type_arg,
                env_var_instance,
            )
        return self._envvar_intersection(ctx.api, type_arg)


def plugin(version: str) -> type[TypedEnvsPlugin]:
    """Mypy entry point for typed_envs plugin."""

    return TypedEnvsPlugin
