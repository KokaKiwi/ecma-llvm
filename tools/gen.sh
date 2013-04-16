#!/bin/sh

CURDIR=`dirname $0`

echo 'Generating headers...'
python2 $CURDIR/genheaders.py

echo 'Generating AST header...'
python2 $CURDIR/genast.py

echo 'Generating visitor header...'
python2 $CURDIR/genvisitor.py
