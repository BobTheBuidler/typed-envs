import asyncio

import pytest

from typed_envs import EnvironmentVariable, create_env


def test_int_env():
    """Test integer environment variable creation and operations.

    Verifies that the environment variable created using :func:`create_env` behaves
    like an instance of :class:`int` and is an instance of :class:`EnvironmentVariable`.
    It checks support for arithmetic operations such as addition, subtraction,
    multiplication, and division.

    See Also:
        - :func:`create_env`
        - :class:`EnvironmentVariable`
    """
    env = create_env("TEST", int, 10)
    assert isinstance(env, int)
    assert isinstance(env, EnvironmentVariable)
    env + 10
    env - 10
    env * 10
    env / 10


def test_str_env():
    """Test string environment variable creation and operations.

    Checks that the environment variable behaves like an instance of :class:`str`
    and is an instance of :class:`EnvironmentVariable`. It verifies support for
    string operations like `upper` and `lower`. Also ensures that adding an integer
    to the string environment variable raises a :class:`TypeError`.

    Note:
        If the default value is not a string, it is cast as a string.

    See Also:
        - :func:`create_env`
        - :class:`EnvironmentVariable`
    """
    env = create_env("TEST", str, 10)
    assert isinstance(env, str)
    assert isinstance(env, EnvironmentVariable)
    env.upper()
    env.lower()
    with pytest.raises(TypeError):
        env + 10


def test_complex_env():
    """Test complex environment variable creation with custom type.

    Verifies that the environment variable created is an instance of
    :class:`asyncio.Semaphore` and :class:`EnvironmentVariable`. It checks for the
    presence of `acquire` and `release` methods, specific to semaphore objects.

    See Also:
        - :func:`create_env`
        - :class:`EnvironmentVariable`
        - :class:`asyncio.Semaphore`
    """
    env = create_env("TEST", asyncio.Semaphore, default=10, string_converter=int)
    assert isinstance(env, asyncio.Semaphore)
    assert isinstance(env, EnvironmentVariable)
    assert hasattr(env, "acquire")
    assert hasattr(env, "release")


def test_bool_conversion():
    """Test boolean environment variable conversion behavior.

    Demonstrates that a boolean environment variable behaves like an :class:`int`
    due to subclassing, and cannot be directly checked as an instance of :class:`bool`,
    verified by expecting an assertion failure when checking its instance type.

    Note:
        You can't subclass a bool, so it's the only type that breaks our type checking.
        We subclass :class:`int` as a workaround to create a bool-like class.

    See Also:
        - :func:`create_env`
        - :class:`EnvironmentVariable`
    """
    env = create_env("TEST", bool, default="test")
    # You can't subclass a bool so its the only type that breaks our type checking
    with pytest.raises(AssertionError):
        assert isinstance(env, bool)
    assert isinstance(env, int)
