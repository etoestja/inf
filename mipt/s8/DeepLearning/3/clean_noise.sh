#!/bin/bash
for a in $(find|grep noise|grep csv)
do
    echo $a
    rm $a
done
