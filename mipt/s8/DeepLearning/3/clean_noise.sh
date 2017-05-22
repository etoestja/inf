#!/bin/bash
for a in $(find|grep noise|grep csv)
do
    rm $a
done
