#!/usr/bin/env bash

CFLAGS="-I/Users/drufat/Applications/anaconda/include/python2.7 -g -O2"
LDFLAGS="-L/Users/drufat/Applications/anaconda/lib -lpython2.7"
gcc $CFLAGS $LDFLAGS -o example1 example1-example1.o
otool -L example1
./example1
install_name_tool -change "libpython2.7.dylib" "/Users/drufat/Applications/anaconda/lib/libpython2.7.dylib" example1
otool -L example1
./example1