#!/bin/bash
for ((i=1; i<=128; i++))
do
line1="$(sed -n "${i}p" inputs.txt)"
line2="$(sed -n "${i}p" outputs.txt)"
line3="$line1$line2"
echo $line3 >> final.txt
done
