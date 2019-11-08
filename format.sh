#!/usr/bin/env bash

args=-i
source=main.c matrix/matrix.c
headers=main.h matrix/matrix.h

clang-format ${args} ${source} ${headers}
