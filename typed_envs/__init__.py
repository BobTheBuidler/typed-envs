
from typing import Any, Callable, Optional, Type, TypeVar

from typed_envs.env_var import EnvironmentVariable
from typed_envs.factory import EnvVarFactory, logger, default_factory
from typed_envs.registry import ENVIRONMENT, _ENVIRONMENT_VARIABLES_SET_BY_USER, _ENVIRONMENT_VARIABLES_USING_DEFAULTS

"""
This module is used to create specialized EnvironmentVariable objects.
that behave exactly the same as any other instance of the provided `typ`.

EnvironmentVariable class is used for:
 - enhancing type hints for the returned instances
 - enhancing __repr__ of the returned instance that hold values you set with env vars.
    NOTE: This is just a helper class to create custom wrapper classes on the fly.
You must never initialize these directly. You must use the `create_env` function either on this module or on an `EnvVarFactory` to initialize your env vars.
"""

T = TypeVar('T')

def create_env(
    name: Optional[str], 
    typ: Type[T], 
    default: Any,
    *init_args, 
    string_converter: Optional[Callable[[str], Any]] = None, 
    verbose: bool = True,
    **init_kwargs
) -> "EnvironmentVariable[T]":
    """
    Returns a new EnvironmentVariable object with no prefix specified.
    
    Functionally, `EnvironmentVariable` objects will work exactly the same as any instance of specified `typ`.

    In the example below, `some_var` can be used just like as any other `int` object.
    
    ```
    import typed_envs
    some_var = typed_envs.create_env("SET_WITH_THIS_ENV", int, 10)

    >>> isinstance(some_var, int)
    True
    >>> isinstance(some_var, EnviromentVariable)
    True
    ```
    There are only 2 differences between `some_var` and `int(10)`:
    - `some_var` will properly type check as all of the following: `int`, `EnvironmentVariable`, `EnvironmentVariable[int]`
    - `some_var.__repr__()` will include contextual information about the `EnvironmentVariable`.
    
    ```
    >>> some_var
    <EnvironmentVariable[name=`SET_WITH_THIS_ENV`, type=int, default_value=10, current_value=10, using_default=True]>
    >>> str(some_var)
    "10"
    >>> some_var + 5
    15
    >>> 20 / some_var
    2
    ```
    """
    return default_factory.create_env(name, typ, default, *init_args, string_converter=string_converter, verbose=verbose, **init_kwargs)

__all__ = ["create_env", "EnvVarFactory", "ENVIRONMENT", "_ENVIRONMENT_VARIABLES_SET_BY_USER", "_ENVIRONMENT_VARIABLES_USING_DEFAULTS"]

# Just putting these here so I don't accidentally remove the 'unused' import
EnvironmentVariable
logger
