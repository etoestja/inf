#!/bin/bash

while true
do
    python generate.py > test.in
    cat test.in | ./main > out1
    cat test.in | ./main_s > out2
    diff out1 out2 > /dev/null
    if [ "X$?" != "X0" ]
    then
        cat test.in
        echo "WA"
        exit
    else
        echo "OK"
    fi
done
