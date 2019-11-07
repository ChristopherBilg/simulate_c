#!/usr/bin/env bash

args=-i
source=matrix.c
headers=matrix.h

clang-format ${args} ${source} ${headers}
