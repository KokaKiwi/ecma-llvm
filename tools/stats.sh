#!/bin/bash
HERE=$(dirname $0)
PROJECT_ROOT=$(dirname ${HERE})

cd ${PROJECT_ROOT}
cloc --exclude-dir=build --out=STATS --quiet --progress-rate=0 .
echo >> STATS

echo "Contributors (git):" >> STATS
git shortlog -s -n >> STATS
