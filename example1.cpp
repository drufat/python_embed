#include <Python.h>

int main() {

  printf("Path:             %ls \n", Py_GetPath());
  printf("Prefix:           %ls \n", Py_GetPrefix());
  printf("ExecPrefix:       %ls \n", Py_GetExecPrefix());
  printf("ProgramFullPath:  %ls \n", Py_GetProgramFullPath());

  Py_Initialize();
  PyRun_SimpleString("import time as t; print('Today is', t.ctime(t.time()))");
  Py_Finalize();

  return 0;
}
