from typing import TYPE_CHECKING, Any, Callable, NewType

if TYPE_CHECKING:
    pass


VarName = NewType("VarName", str)
VarValue = NewType("VarValue", str)

EnvRegistry = NewType("EnvRegistry", dict[VarName, "EnvironmentVariable"])

StringConverter = Callable[[str], Any]
