#!/bin/bash

a="0.4 0.6 1.2 1.7"
for i in $a
do
    ./a.out 99 200000 $i
done
