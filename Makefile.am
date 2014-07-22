pyexec_LTLIBRARIES = hello.la
ACLOCAL_AMFLAGS = -I m4

hellodir = $(pkgpythondir)
hello_PYTHON =

hello_la_SOURCES = hellomodule.c
hello_la_CFLAGS = $(PYTHON_CFLAGS)
hello_la_LDFLAGS = -module -avoid-version -export-symbols-regex "^(PyInit_.*|init.*)"
