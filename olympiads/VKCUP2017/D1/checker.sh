#!/bin/bash
for a in $(ls|grep test|grep -v ans)
do
    cat $a | ./D1 > out.txt

    cat out.txt | python restore.py > out1.txt

    echo "TEST $a"
    if [ -e ${a}.ans ]
    then
        diff out.txt ${a}.ans > diff_out
        if [ "X$?" == "X1" ]
        then
            echo "Test $a ERROR"
            cat diff_out
        else
            echo "Test $a ANS OK"
        fi
    fi
    diff $a out1.txt
    if [ "X$?" == "X1" ]
    then
        echo "Restoring FAILED"
    else
        echo "OK"
    fi
done
