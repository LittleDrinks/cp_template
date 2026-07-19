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
        e(f'g++ -std=gnu++20 {cpp} -o {exe}')
        return [str(exe.resolve())]

q = 'k'
G = build(Path(q+'_gen'))
B = build(Path(q+'_bf'))
M = build(Path(q))
i = '.in'
o = '.out'
a = '.ans'
while 1:
    s.run(G, stdout=open(i,'w'))
    s.run(B, stdin=open(i), stdout=open(a,'w'))
    s.run(M, stdin=open(i), stdout=open(o,'w'))
    if open(o).read().split() == open(a).read().split():
        print('AC')
    else:
        print('WA')
        break
