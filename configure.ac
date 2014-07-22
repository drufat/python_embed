AC_PREREQ([2.69])
AC_INIT([EmbedPython], [0.1])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AM_PROG_AR
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([hellomodule.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_CC

# Python checks
AM_PATH_PYTHON(2.7)
PYTHON_INC=`$PYTHON -c 'import distutils.sysconfig as s; print(s.get_python_inc())'`
PYTHON_CFLAGS="-I$PYTHON_INC"
PYTHON_LIBS="-lpython$PYTHON_VERSION"

AC_SUBST([PYTHON_INC])
AC_SUBST([PYTHON_LIBS])
AC_SUBST([PYTHON_CFLAGS])

AC_CONFIG_FILES([Makefile .includes])
AC_OUTPUT
