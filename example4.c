#include <Python.h>

int
main(int argc, char *argv[])
{
    Py_NoSiteFlag=1;
    Py_Initialize();

    PyRun_SimpleString("print(1 + 1)");
    Py_Finalize();

    return 0;
}
