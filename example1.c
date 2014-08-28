#include <Python.h>

int
main(int argc, char *argv[])
{

    printf("Path:             %S\n", Py_GetPath());
    printf("Prefix:           %S\n", Py_GetPrefix());
    printf("ExecPrefix:       %S\n", Py_GetExecPrefix());
    printf("ProgramFullPath:  %S\n", Py_GetProgramFullPath());

    Py_Initialize();

    PyRun_SimpleString("from time import time,ctime\n"
                     "print('Today is', ctime(time()))\n");
    Py_Finalize();

    return 0;
}
