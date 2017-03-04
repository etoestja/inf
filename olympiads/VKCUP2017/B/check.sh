#!/bin/bash

i=0
while true
do
    python gen.py > test0
    cat test0 | time ./B > result

    cat test0 > to_check
    cat result >> to_check

    res=$(cat to_check | ./Bcheck)
    echo "$i RESULT $res"
    if [ "X$res" == "X0" ]
    then
        exit
    fi
    let i=i+1
done
