#!/bin/bash

while true
do
    rm testB
    python generate.py > testB
    lin=$(cat testB | wc -l)

    if (( $lin > 0 ))
    then
        cat testB | ./B > /dev/null
        if [ "X$?" == "X0" ]
        then
          echo "OK"  
        else
          echo "ERROR"
          cat testB
          exit
        fi
    fi
done
