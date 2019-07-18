#include <Python.h>
#include <iostream>

static const char *source = R"(

def multiply(a, b):
    print("PY: Will compute", a, "times", b)
    c = 0
    for _ in range(0, a):
        c = c + b
    return c

)";

void print(PyObject *obj) { PyObject_Print(obj, stdout, Py_PRINT_RAW); }

int main() {

  Py_Initialize();

  auto globals = PyDict_New();
  auto locals = PyDict_New();

  PyDict_SetItemString(globals, "__builtins__", PyEval_GetBuiltins());

  auto result = PyRun_String(source, Py_file_input, globals, locals);
  Py_DecRef(globals);
  Py_DecRef(result);

  auto func = PyDict_GetItemString(locals, "multiply");
  Py_IncRef(func);
  Py_DecRef(locals);

  auto args = Py_BuildValue("ii", 2, 3);
  result = PyObject_CallObject(func, args);
  Py_DecRef(func);
  Py_DecRef(args);

  std::cout << "CC: Result of call: " << PyLong_AsLong(result) << std::endl;
  Py_DecRef(result);

  Py_Finalize();
  return 0;
}
