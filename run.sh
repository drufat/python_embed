#!/bin/bash -x

set -e
make

export LD_LIBRARY_PATH=`python -c "import sysconfig as s; print(s.get_config_var('LIBDIR'))"`
export PYTHONPATH=. 
./example1
./example2 multiply multiply 2 3
./example3

