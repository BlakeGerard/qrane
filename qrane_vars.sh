pbase=`which python | sed -e 's/bin\/python//g'`
export QRANE_CONDA_BASE=${pbase}
CONDALIB=${QRANE_CONDA_BASE}/lib
CONDAINC=${QRANE_CONDA_BASE}/include

echo $CONDAPATH

export QRANE_HOME=.
export AQUMA_HOME=../aquma

export LD_LIBRARY_PATH=`pwd`/lib/ntl/lib:`pwd`/lib/barvinok/lib:`pwd`/lib/bison/lib:${CONDALIB}:${LD_LIBRARY_PATH}
