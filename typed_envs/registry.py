from typing import Final

from typed_envs.typing import EnvRegistry


ENVIRONMENT: Final[EnvRegistry] = EnvRegistry({})
_ENVIRONMENT_VARIABLES_SET_BY_USER: Final[EnvRegistry] = EnvRegistry({})
_ENVIRONMENT_VARIABLES_USING_DEFAULTS: Final[EnvRegistry] = EnvRegistry({})

__all__ = [
    "ENVIRONMENT",
    "_ENVIRONMENT_VARIABLES_SET_BY_USER",
    "_ENVIRONMENT_VARIABLES_USING_DEFAULTS",
]
