#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Require qasm file. Aborting ..."
  exit
fi

qfile=$1

if [ ! -f $qfile ]; then
  echo "File $qfile not found. Aborting ..."
  exit
fi

./qrane $qfile > dump.txt

line1=`cat dump.txt | grep -n -e '--- Codegen ---' | sed -e 's/:.*$//g'`
line2=`cat dump.txt | grep -n -e '--- Stats ---' | sed -e 's/:.*$//g'`
lines=`cat dump.txt | wc -l`
bottom=$(($lines-$line1))
body=$(($line2-$line1))
body=$(($body-3))

echo "Line1: $line1"
echo "Line2: $line2"

echo "Found:"
tail -n $bottom dump.txt | head -n $body | sed -e 's/q//g' -e 's/\[//g' -e 's/\]//g' | sed -e 's/c/C/g' -e 's/x/X/g' -e 's/y/Y/g' -e 's/z/Z/g' > recovered.c

gcc harness-qasm.c
./a.out
