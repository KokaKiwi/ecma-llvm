#!/bin/bash
HERE=$(dirname $0)
PROJECT_ROOT=$(dirname ${HERE})

cd ${PROJECT_ROOT}
cloc --exclude-dir=build --not-match-d='\..*' --out=STATS .
echo >> STATS

echo "Contributors (git):" >> STATS
git shortlog -s -n >> STATS
