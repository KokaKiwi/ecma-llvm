#!/bin/bash

HERE=$(dirname $0)
ECMAC="${HERE}/build/bin/ecmac"

SAMPLES_DIR="${HERE}/samples"
SAMPLES=$(find ${SAMPLES_DIR} -type f -name "*.js")

OPTFLAGS=(-globaldce -globalopt -gvn)

for sample in ${SAMPLES[@]}; do
    ( ${ECMAC} ${sample} | opt -S ${OPTFLAGS[@]} ) > ${sample/.js/.ll} 2> ${sample/.js/.log}
done
