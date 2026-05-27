import sys, argparse, subprocess as s
from pathlib import Path

G, R, P, N = '\033[32m', '\033[31m', '\033[35m', '\033[0m'

p = argparse.ArgumentParser()
p.add_argument('q')
p.add_argument('f', nargs='?')
ag = p.parse_args()

q: str = ag.q
f = ag.f or q
cmd = [sys.executable, 'run.py', f]
for i in Path(f'samples-{q.capitalize()}').glob('*.in'):
    print(i, end=' ', flush=1)
    o = i.with_suffix('.out')
    a = i.with_suffix('.ans')
    try:
        k = s.run(cmd, timeout=2, input=i.read_text(), stdout=s.PIPE, stderr=s.PIPE, text=1)
        o.write_text(k.stdout)
        print(f'{G}AC{N}' if k.stdout.rstrip() == a.read_text().rstrip() else f'{R}WA{N}')
        if k.stderr: print(f'{R}{k.stderr}{N}')
    except s.TimeoutExpired as k:
        print(f'{P}TLE or RE{N}')
        if k.stderr: print(f'{R}{k.stderr}{N}')
