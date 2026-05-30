import sys
import subprocess as s
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

f = sys.argv[1]
q = f[0]
g, r, p, n = '\033[32m', '\033[31m', '\033[35m', '\033[0m'

cmd = build(Path(f))
for i in Path(f'samples-{q.capitalize()}').glob('*.in'):
    print(i, end=' ', flush=1)
    o = i.with_suffix('.out')
    a = i.with_suffix('.ans')
    try:
        k = s.run(cmd, timeout=2, stdin=open(i), stdout=open(o,'w'), stderr=s.PIPE, text=1)
        print(f"{g}AC{n}" if o.read_text().split() == a.read_text().split() else f"{r}WA{n}")
        if k.stderr: print(f'{r}{k.stderr}{n}')
    except s.TimeoutExpired as k:
        print('TLE or RE')
        if k.stderr: print(f'{r}{k.stderr}{n}')