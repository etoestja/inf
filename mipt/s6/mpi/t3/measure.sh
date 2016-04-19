#!/bin/bash

pmin=1
pmax=15

kn=5

p=$pmin
echo "["
while (( $p <= $pmax ))
do
    k=0
    echo -n "[$p, "
    while (( $k < $kn ))
    do
        res1=$(./main $p 1000000000 2>&1|grep -aEo "[0-9.]+")
        echo -n "$res1, "
        let k=k+1
    done
    echo "],"
    let p=p+1
done
echo "]"
