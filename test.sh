#!/bin/bash

# Compile
sol_path="$1"

g++ "$sol_path" -o "./slows/sol"
g++ "./slows/slow.cpp" -o "./slows/slow"
g++ -std=c++20 "./slows/gen.cpp" -o "./slows/gen"

# shellcheck disable=SC1073
for((i = 1; ; i++)); do
  echo $i
  ./slows/gen $i > ./slows/test.txt
  ./slows/slow < ./slows/test.txt > ./slows/slow_sol.txt
  ./slows/sol < ./slows/test.txt > ./slows/sol.txt
  diff -w ./slows/sol.txt ./slows/slow_sol.txt || break
done