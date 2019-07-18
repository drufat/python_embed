#!/bin/bash -x

set -e
make

export LD_LIBRARY_PATH=`python -c "import sysconfig as s; print(s.get_config_var('LIBDIR'))"`
./example1
./example2
./example3

