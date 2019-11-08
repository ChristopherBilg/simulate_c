#!/usr/bin/env bash

args=-i
declare -a source=(
    main.c
    matrix/matrix.c
)
declare -a headers=(
    main.h
    matrix/matrix.h
)

declare -a all_files=("${source[@]}" "${headers[@]}")

for i in "${all_files[@]}"
do
   echo "Formatting all_files file: $i"
    clang-format ${args} $i
done
