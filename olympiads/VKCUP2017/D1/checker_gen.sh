#!/bin/bash
a=gen_test
while true
do
    python generator.py > $a
    cat $a | ./D1 > out.txt

    cat out.txt | python restore.py > out1.txt
    cat $a

    diff $a out1.txt
    if [ "X$?" == "X1" ]
    then
        echo "Restoring FAILED"
        exit
    else
        echo "OK"
    fi
done
