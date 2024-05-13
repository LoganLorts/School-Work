#!/bin/sh

echo 0 >results.txt
tests=20
while [ "$tests" -ne 0 ]
do	
    tests="`expr $tests - 1`"
    echo $tests
    rm your_outputs/*
    ps -axc | sort -r >your_outputs/out_axc.txt 
    ps -ac  | sort -r >your_outputs/out_ac.txt 
    diff -r your_outputs/ goals/ && echo 100 >results.txt && break
done
echo "Your grade is:"
cat results.txt
