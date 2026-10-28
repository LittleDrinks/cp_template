import sys
import subprocess as s
from os import system as e
from pathlib import Path

def build(p: Path):
    if p.suffix == '.py':
        return [sys.executable, str(p)]
    else:
        cpp = p.with_suffix('.cpp')
        exe = p.with_suffix('.exe')
        if not exe.exists() or exe.stat().st_mtime < cpp.stat().st_mtime:
            s.run(['g++', '-std=gnu++20', cpp, '-o', exe], check=1)
        return [str(exe.resolve())]

s.run(build(Path(sys.argv[1])))