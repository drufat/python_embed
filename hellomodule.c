#include <Python.h>

static PyObject*
say_hello(PyObject* self, PyObject* args)
{
    const char* name;

    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;

    printf("Hello %s!\n", name);

    Py_RETURN_NONE;
}

static PyMethodDef Methods[] =
{
    {"say_hello", say_hello, METH_VARARGS, "Greet somebody."},
    {NULL, NULL, 0, NULL}
};

#if PY_MAJOR_VERSION >= 3

static struct PyModuleDef module = {
   PyModuleDef_HEAD_INIT,
   "hello",
   "hello documentation.",
   -1,
   Methods
};

PyMODINIT_FUNC
PyInit_hello(void)
{
    return PyModule_Create(&module);
}

#else

PyMODINIT_FUNC
inithello(void)
{
    (void) Py_InitModule("hello", Methods);
}

#endif
