#!/bin/bash
a=gen_test__
while true
do
    python generator.py > $a
    cat $a | ./D1 > out__.txt

    cat out__.txt | python restore.py > out1__.txt
    cat $a

    diff $a out1__.txt
    if [ "X$?" == "X1" ]
    then
        echo "Restoring FAILED"
        exit
    else
        echo "OK"
    fi
done
