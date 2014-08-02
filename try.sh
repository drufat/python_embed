#!/usr/bin/env bash
autoreconf -f -i

export PYTHON=/Users/drufat/Applications/anaconda/bin/python
#export PYTHON=/usr/bin/python
#export PYTHON=/usr/local/bin/python3
#export PYTHON=/Users/drufat/Source/cpython/usr/bin/python3.5

./configure
make

./example1
nm example1
otool -L example1