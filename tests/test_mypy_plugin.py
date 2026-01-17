from __future__ import annotations

import textwrap
import os
import sys
from pathlib import Path

import pytest

mypy = pytest.importorskip("mypy.api")


def _run_mypy(tmp_path: Path, source: str) -> tuple[str, str, int]:
    repo_root = Path(__file__).resolve().parents[1]
    source_path = tmp_path / "sample.py"
    config_path = tmp_path / "mypy.ini"

    source_path.write_text(textwrap.dedent(source))
    config_path.write_text(
        textwrap.dedent(
            """
            [mypy]
            plugins = typed_envs.mypy_plugin
            """
        ).lstrip()
    )

    prior_mypy_path = os.environ.get("MYPYPATH")
    prior_python_path = os.environ.get("PYTHONPATH")
    sys_path_snapshot = list(sys.path)
    os.environ["MYPYPATH"] = (
        str(repo_root)
        if not prior_mypy_path
        else f"{repo_root}{os.pathsep}{prior_mypy_path}"
    )
    os.environ["PYTHONPATH"] = (
        str(repo_root)
        if not prior_python_path
        else f"{repo_root}{os.pathsep}{prior_python_path}"
    )
    sys.path.insert(0, str(repo_root))
    try:
        stdout, stderr, exit_status = mypy.run(
            [
                "--config-file",
                str(config_path),
                str(source_path),
            ]
        )
    finally:
        sys.path[:] = sys_path_snapshot
        if prior_mypy_path is None:
            os.environ.pop("MYPYPATH", None)
        else:
            os.environ["MYPYPATH"] = prior_mypy_path
        if prior_python_path is None:
            os.environ.pop("PYTHONPATH", None)
        else:
            os.environ["PYTHONPATH"] = prior_python_path
    return stdout, stderr, exit_status


def test_mypy_plugin_allows_underlying_types(tmp_path: Path) -> None:
    source = """
        import typed_envs
        from typed_envs import EnvVarFactory

        some_var = typed_envs.create_env("SOME_VAR", int, 10)
        factory = EnvVarFactory()
        other_var = factory.create_env("OTHER_VAR", str, "hi")

        def takes_int(x: int) -> None:
            print(x)

        def takes_str(x: str) -> None:
            print(x)

        takes_int(some_var)
        takes_str(other_var)
        """
    stdout, stderr, exit_status = _run_mypy(tmp_path, source)
    assert exit_status == 0, stdout
    assert "error:" not in stdout
    assert stderr == ""
