#!/bin/bash

thr=15
#thr=40

while true
do
    stat=$(upower -i /org/freedesktop/UPower/devices/battery_BAT0|grep "percentage"|cut -d ":" -f 2|grep -aEo "[0-9]+")
    echo $stat
    if (( $stat < $thr ))
    then
        echo "warning"
        mplayer /home/sergei/Music/alarm/alarm01.ogg
    fi
    sleep 1
done
