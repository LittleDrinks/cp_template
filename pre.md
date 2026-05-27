## run.sh
```sh
#!/bin/bash
F=$1
[[ "$F" != *.* ]] && F+=.cpp
if [[ "$F" == *.cpp ]]; then
    BIN="${F%.cpp}"
    if [[ ! -f "$BIN" || "$F" -nt "$BIN" ]]; then
        g++ -std=gnu++20 "$F" -o "$BIN"
    fi
    "./$BIN"
    exit $?
fi
if [[ "$F" == *.py ]]; then
    python3 "$F"
    exit $?
fi
```
## 土质 cph
```python
import sys
import subprocess as s
from glob import glob

q = sys.argv[1]
f = sys.argv[2] if len(sys.argv) > 2 else f"{q}.cpp"
tid = sys.argv[3] if len(sys.argv) > 3 else None
g, r, p, n = '\033[32m', '\033[31m', '\033[35m', '\033[0m'
cmd = f"./run.sh {f}"

for i in glob(f"samples-{q.capitalize()}/*.in"):
    if (tid and tid not in i):
        continue
    print(i, end=' ', flush=1)
    t = i[:-2]
    try:
        k = s.run(cmd, shell=1, timeout=2, stdin=open(f'{t}in'), stdout=open(f'{t}out','w'), stderr=s.PIPE)
        o = open(f"{t}out").read().rstrip()
        a = open(f"{t}ans").read().rstrip()
        print(f"{g}AC{n}" if o == a else f"{r}WA{n}")
        if k.stderr: print(f"{r}{k.stderr.decode()}{n}")
    except s.TimeoutExpired as k:
        print(f"{p}TLE or RE{n}")
        if k.stderr: print(f"{r}{k.stderr.decode()}{n}")

```

## 对拍
```sh
#!/bin/bash
while true; do
    ./run.sh a_gen > .in
    ./run.sh a < .in > .out
    ./run.sh a.py < .in > .ans
    if diff ".ans" ".out" > /dev/null; then
        echo "AC"
    else
        echo "WA"
        break
    fi
done
```