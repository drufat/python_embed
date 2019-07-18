#!/usr/bin/env bash
make clean
rm -rf Makefile Makefile.in \
        *.m4 m4 \
        .deps .libs \
        clean ar-lib autom4te.cache compile config.* configure install-sh libtool ltmain.sh m4 missing stamp-h1 \
        depcomp __pycache__
