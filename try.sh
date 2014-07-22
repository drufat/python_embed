#!/usr/bin/env bash
autoreconf -f -i

#export PYTHON=/Users/drufat/Applications/anaconda/bin/python
#export PYTHON=/usr/bin/python
#export PYTHON=/usr/local/bin/python3
export PYTHON=/Users/drufat/Source/cpython/usr/bin/python3.5

./configure
make

PYTHONPATH=.libs $PYTHON -c "import hello; print(hello.__file__)"
PYTHONPATH=.libs $PYTHON -c "import hello; hello.say_hello('John')"
nm .libs/hello.so
