#!/bin/bash
# chmod +x check.sh
g++ -std=gnu++20 -O2 $1.cpp -o $1
g++ -std=gnu++20 -O2 $1_gen.cpp -o $1_gen
g++ -std=gnu++20 -O2 $1_bf.cpp -o $1_bf
while true; do
    ./$1_gen > .in
    ./$1_bf < .in > .ans
    ./$1 < .in > .out
    if diff ".out" ".ans" > /dev/null; then
        echo "AC"
    else
        echo "WA"
        break
    fi
done
