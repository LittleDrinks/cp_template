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