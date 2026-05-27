import sys
import subprocess as s
from pathlib import Path

f = Path(sys.argv[1])

if f.suffix == '.py':
    cmd = [sys.executable, f]
else:
    src = f.with_suffix('.cpp')
    exe = f.with_suffix('.exe')
    if not exe.exists() or exe.stat().st_mtime < src.stat().st_mtime:
        if s.run(['g++', '-std=gnu++20', src, '-o', exe]).returncode:
            sys.exit()
    cmd = [exe.absolute()]

s.run(cmd)