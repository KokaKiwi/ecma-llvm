#!/bin/bash
HERE=$(dirname $0)

SRC="$1"
DST=${SRCS/.svg/.pdf}

if [ $# -gt 1 ]; then
    DST="$2"
fi

inkscape -z -D --file ${SRC} --export-pdf ${DST}
