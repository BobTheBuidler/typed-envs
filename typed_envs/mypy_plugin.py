"""Mypy plugin for typed_envs.

This plugin teaches mypy to treat typed_envs.create_env(...) and
EnvVarFactory.create_env(...) as returning the *underlying* type argument,
even though the runtime object is a dynamic EnvironmentVariable subclass.

Enable in your mypy config:

    [mypy]
    plugins = typed_envs.mypy_plugin

This keeps runtime behavior unchanged while allowing:

    some_var = typed_envs.create_env("SOME_VAR", int, 10)
    def foo(x: int) -> None: ...
    foo(some_var)  # passes with the plugin enabled
"""

from __future__ import annotations

from typing import Callable, Iterable

from mypy.plugin import FunctionContext, MethodContext, Plugin
from mypy.types import (
    AnyType,
    CallableType,
    Instance,
    Overloaded,
    Type,
    TypeOfAny,
    TypeType,
    UnionType,
    get_proper_type,
)


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


def _unwrap_type_argument(arg_type: Type) -> Type | None:
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
        return UnionType.make_union([item.ret_type for item in items])
    if isinstance(proper, UnionType):
        items: list[Type] = []
        for item in proper.items:
            unwrapped = _unwrap_type_argument(item)
            if unwrapped is None:
                return None
            items.append(unwrapped)
        return UnionType.make_union(items)
    return None


def _create_env_function_hook(ctx: FunctionContext) -> Type:
    arg_type = _find_arg_type(ctx, ("typ",))
    if arg_type is None:
        return ctx.default_return_type
    unwrapped = _unwrap_type_argument(arg_type)
    return unwrapped or ctx.default_return_type


def _create_env_method_hook(ctx: MethodContext) -> Type:
    arg_type = _find_arg_type(ctx, ("env_var_type",))
    if arg_type is None:
        return ctx.default_return_type
    unwrapped = _unwrap_type_argument(arg_type)
    return unwrapped or ctx.default_return_type


class TypedEnvsPlugin(Plugin):
    """Plugin that maps typed_envs env factories to their underlying types."""

    def get_function_hook(
        self, fullname: str
    ) -> Callable[[FunctionContext], Type] | None:
        if fullname in _CREATE_ENV_FUNCTIONS:
            return _create_env_function_hook
        return None

    def get_method_hook(
        self, fullname: str
    ) -> Callable[[MethodContext], Type] | None:
        if fullname in _CREATE_ENV_METHODS:
            return _create_env_method_hook
        return None


def plugin(version: str) -> type[TypedEnvsPlugin]:
    """Mypy entry point for typed_envs plugin."""

    return TypedEnvsPlugin
