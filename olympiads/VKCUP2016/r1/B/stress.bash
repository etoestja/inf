#!/bin/bash
i=1
while true
do
    ./gen > input0
#    cat input0 | . "$1" > output0
#    cat input0 | . "$2" > output1

    cat input0 | ./sol > output0

    res="$(cat input0 | head -n 1)"
    res2="$(cat output0 | head -n 1)"
    python check.py input0 output0
    if [ $? != 0 ]
    then
        echo "$i WRONG ANSWER $res $res2"
        exit
    else
        echo "$i CORRECT $res $res2"
    fi
    let i=i+1
done
