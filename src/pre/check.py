import sys, subprocess as s
from pathlib import Path

def run(f, i=None, o=None):
    r = s.run([sys.executable, 'run.py', f], input=i, capture_output=1, text=1).stdout
    if o: Path(0).write_text(r)
    return r

G = 'a_gen'
B = 'a_bf'
M = 'a'

while 1:
    t = run(G, o='.in')
    o = run(B, t, '.out')
    a = run(M, t, '.ans')
    if o != a:
        print('WA')
        break
    else:
        print('AC')
