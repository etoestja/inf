#!/bin/bash

python gen.py > test0
cat test0 | time ./D
cat test0 | time ./sol2
