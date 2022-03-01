#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Require input directory with recovered C-files and output directory."
  exit
fi

cdir=$1
outdir=$2

if [ ! -d $cdir ]; then
  echo "Directory $cdir not found"
  exit 0
fi

if [ ! -d $outdir ]; then
  echo "Creating $outdir ..."
  mkdir $outdir
fi

for qq in `ls $cdir/*.c`; do
  newname=`echo $qq | sed -e 's/^.*\///g' -e 's/\.c//g'`
  echo "$qq ==> $newname"
  gcc $qq
  ./a.out
  newqasm=${newname}.qasm
  mv $newqasm $outdir/
done
