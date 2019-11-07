#!/usr/bin/env bash

args=-i
source=main.c matrix.c
headers=main.h matrix.h

clang-format ${args} ${source} ${headers}
