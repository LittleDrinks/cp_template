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