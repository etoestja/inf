#!/bin/bash
a=gen_test
while true
do
    python generator.py > $a
    cat $a | ./D1 > out.txt
    cat $a | python D.py > out1.txt

    cat $a

    diff out.txt out1.txt
    if [ "X$?" == "X1" ]
    then
        echo "FAILED"
        exit
    else
        echo "OK"
    fi
done
