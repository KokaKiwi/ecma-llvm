#!/bin/bash

HERE=$(dirname $0)
HERE=$(cd ${HERE} && pwd)
ECMAC="${HERE}/build/bin/ecmac"
LIBSDIR="${HERE}/build/lib"

SAMPLES_DIR="${HERE}/samples"
SAMPLES=$(find ${SAMPLES_DIR} -type f -name "*.js")

OPTFLAGS=(-globaldce -globalopt -gvn -mem2reg -mergereturn -constmerge)

for sample in ${SAMPLES[@]}; do
    echo "Compiling ${sample}"
    ( ${ECMAC} ${sample} | opt -S ${OPTFLAGS[@]} ) > ${sample/.js/.ll} 2> ${sample/.js/.log}
    llc -O0 ${sample/.js/.ll} > ${sample/.js/.s}
    clang++ -o ${sample/.js/} ${sample/.js/.s} -L${LIBSDIR} -lEcmaRuntime
done
