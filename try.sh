#!/usr/bin/env bash
autoreconf -f -i
./configure
make

./example1
nm example1
