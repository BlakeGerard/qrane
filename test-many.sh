#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Require input directory with QASM files and output directory."
  exit
fi

qasmdir=$1
outdir=$2

if [ ! -d $qasmdir ]; then
  echo "Directory $qasmdir not found"
  exit 0
fi

if [ ! -d $outdir ]; then
  echo "Creating $outdir ..."
  mkdir $outdir
fi

for qq in `ls $qasmdir/*.qasm`; do
  newname=`echo $qq | sed -e 's/^.*\///g' -e 's/\.qasm//g'`
  echo "$qq ==> $newname"
  cfile=${newname}.c
  statfile=${newname}.qstats
  ./qrane --isl -c ${qq} --to_C=${cfile} > ${statfile}
  mv $cfile $outdir/
  mv $statfile $outdir/
done
