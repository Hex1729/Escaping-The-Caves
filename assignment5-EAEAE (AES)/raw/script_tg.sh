#!/bin/bash
for ((i=1; i<=8; i++))
do
    for ((j=1; j<=i; j++))
    do
        for ((k=1; k<=128; k++))
        do
        line1="$(sed -n "${k}p" input/$i/$j.txt)"
        line2="$(sed -n "${k}p" output/$i/$j.txt)"
        line3="$line1 $line2"
        echo $line3 >> final/$i/$j.txt
        done
    done
done
