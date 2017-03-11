#!/bin/bash
for a in $(ls|grep test|grep -v ans)
do
    cat $a | ./D1 > out.txt
    diff out.txt ${a}.ans > diff_out
    if [ "X$?" == "X1" ]
    then
        echo "Test $a ERROR"
        cat diff_out
    else
        echo "Test $a OK"
    fi
done
