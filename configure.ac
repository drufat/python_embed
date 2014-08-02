AC_PREREQ([2.69])
AC_INIT([EmbedPython], [0.1])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AM_PROG_AR
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([example1.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_CC

# Python checks
AM_PATH_PYTHON(3)
PYTHON_INC=`$PYTHON -c "import distutils.sysconfig as s; print(s.get_python_inc())"`
PYTHON_CFLAGS="-I$PYTHON_INC"
PYTHON_LIBRARY=`$PYTHON -c "import distutils.sysconfig as S; import os.path as P; a=S.get_config_var('LIBPL'); b=S.get_config_var('LIBRARY'); p=P.join(a,b); print(p)"`

AC_SUBST([PYTHON_INC])
AC_SUBST([PYTHON_CFLAGS])
AC_SUBST([PYTHON_LIBRARY])

AC_CONFIG_FILES([Makefile .includes])
AC_OUTPUT
