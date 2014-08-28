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

# Make the compilation flags quiet unless V=1 is used
#m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Python checks
AM_PATH_PYTHON(3)
PYTHON_INC=`     PYTHONPATH=. ${PYTHON} -c "import pythonconfig as p; p.include()" `
PYTHON_CFLAGS=`  PYTHONPATH=. ${PYTHON} -c "import pythonconfig as p; p.cflags()" `
PYTHON_LDFLAGS=` PYTHONPATH=. ${PYTHON} -c "import pythonconfig as p; p.ldflags()"`

AC_SUBST([PYTHON_INC])
AC_SUBST([PYTHON_CFLAGS])
AC_SUBST([PYTHON_LDFLAGS])

AC_CONFIG_FILES([Makefile .includes])
AC_OUTPUT
