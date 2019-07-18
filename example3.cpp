#include <Python.h>
#include <iostream>

static const char *source = R"(
import ctypes as ct

@ct.CFUNCTYPE(ct.c_int, ct.c_int)
def func(a):
    print('PY: Got from C', a)
    return a * 2

callback = ct.cast(%p, ct.CFUNCTYPE(None, ct.CFUNCTYPE(ct.c_int, ct.c_int)))
callback(func)

print('PY: Finished the Python part')
)";

static void callback(int (*func)(int)) {
  int arg = 3;
  std::cout << "CC: Calling to Python with arg " << arg << std::endl;
  auto rslt = func(arg);
  std::cout << "CC: Result " << rslt << std::endl;
}

int main() {
  char py_source[1024];
  sprintf(py_source, source, reinterpret_cast<void *>(callback));

  //  std::cout << py_source << std::endl;

  Py_Initialize();
  PyRun_SimpleString(py_source);
  Py_Finalize();

  return 0;
}
