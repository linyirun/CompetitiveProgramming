#!/bin/bash

file1="/Users/billlin/Desktop/Competitive Programming"
file2="/Users/billlin/Desktop/Competitive Programming/input.txt"

if cmp -s "$file1" "$file2"; then
    printf 'The file "%s" is the same as "%s"\n' "$file1" "$file2"
else
    printf 'The file "%s" is different from "%s"\n' "$file1" "$file2"
fi