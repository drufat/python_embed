AC_INIT([EmbedPython], [0.1])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AM_PROG_AR

# Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_CXX
AC_PROG_CC

# Checks for C++11.
AX_CHECK_COMPILE_FLAG([-std=c++11], [CXXFLAGS="$CXXFLAGS -std=c++11"])

# Check for Python.
AM_PATH_PYTHON(,, [:])
AM_CONDITIONAL([HAVE_PYTHON], [test "$PYTHON" != :])
PYTHON_CFLAGS=`python-config --cflags`
PYTHON_LDFLAGS=`python-config --ldflags`
AC_SUBST([PYTHON_CFLAGS])
AC_SUBST([PYTHON_LDFLAGS])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
