Mypy Plugin
===========

typed_envs creates dynamic subclasses at runtime, so mypy cannot infer that
``EnvironmentVariable[T]`` behaves like ``T`` without extra help. The plugin
synthesizes a mypy-only class that inherits from both ``EnvironmentVariable``
and the underlying type so you can use methods from either side.

Enable the plugin
-----------------

.. code-block:: ini

   [mypy]
   plugins = typed_envs.mypy_plugin

For ``pyproject.toml``:

.. code-block:: toml

   [tool.mypy]
   plugins = ["typed_envs.mypy_plugin"]

What the plugin covers
----------------------

- ``EnvironmentVariable[T]`` annotations and aliases.
- ``typed_envs.create_env(...)`` and ``EnvVarFactory.create_env(...)`` returns.
- Unions, optionals, ``Annotated``, ``TypedDict``, ``Tuple``, ``Literal``, and
  ``TypeVar`` bounds/constraints.

Limitations
-----------

- The plugin only affects mypy; runtime behavior is unchanged.
- Other type checkers (e.g., pyright) will not use this plugin.
