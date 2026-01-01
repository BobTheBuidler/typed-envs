from typing import TYPE_CHECKING, Any, Callable, NewType

if TYPE_CHECKING:
    from typed_envs._env_var import EnvironmentVariable

    _EnvRegistry = dict[VarName, EnvironmentVariable]


VarName = NewType("VarName", str)
VarValue = NewType("VarValue", str)

EnvRegistry = NewType("EnvRegistry", "_EnvRegistry")

StringConverter = Callable[[str], Any]
