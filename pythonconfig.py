# -*- coding: utf-8 -*-

import sys
import sysconfig

pyver = sysconfig.get_config_var('VERSION')
getvar = sysconfig.get_config_var

def include():
    print(sysconfig.get_path('include'))


def cflags():
    flags = ['-I' + sysconfig.get_path('include'), '-I' + sysconfig.get_path('platinclude')]
    flags.extend(getvar('CFLAGS').split())
    print(' '.join(flags))

def ldflags():
    libs = getvar('LIBS').split() + getvar('SYSLIBS').split()
    libs.append('-lpython' + pyver + sys.abiflags)
    # add the prefix/lib/pythonX.Y/config dir, but only if there is no
    # shared library in prefix/lib/.
    if not getvar('Py_ENABLE_SHARED'):
        libs.insert(0, '-L' + getvar('LIBPL'))
    if not getvar('PYTHONFRAMEWORK'):
        libs.extend(getvar('LINKFORSHARED').split())
    print(' '.join(libs))

if __name__=='__main__':
    include()
    cflags()
    ldflags()
