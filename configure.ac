AC_INIT([EmbedPython], [0.1])
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AM_PROG_AR

# Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_CXX
AC_PROG_CC

# Check for Python.
echo "checking for python: $(python --version)"
CXXFLAGS="$(python-config --cflags) -std=c++11"
LDFLAGS="$(python-config --ldflags)"
echo "CXXFLAGS: $CXXFLAGS"
echo "LDFLAGS: $LDFLAGS"
LIBDIR="$(python -c 'import sysconfig as s; print(s.get_config_var("LIBDIR"))')"
echo "LIBDIR: $LIBDIR"
LDFLAGS="-L$LIBDIR $LDFLAGS"

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

