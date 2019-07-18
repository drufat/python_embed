#include <Python.h>
#include <iostream>

int main(int argc, char *argv[]) {

  if (argc < 3) {
    std::cerr << "Usage: call pythonfile funcname [args]" << std::endl;
    return 1;
  }

  Py_Initialize();

  auto name = PyUnicode_FromString(argv[1]);
  /* Error checking of pName left out */
  auto module = PyImport_Import(name);

  if (!module) {
    PyErr_Print();
    std::cerr << "Failed to load " << argv[1] << std::endl;
    Py_Finalize();
    return 1;
  }

  auto func = PyObject_GetAttrString(module, argv[2]);
  if (!func) {
    PyErr_Print();
    std::cerr << "Cannot find function " << argv[2] << std::endl;
    Py_Finalize();
    return 1;
  }

  if (!PyCallable_Check(func)) {
    std::cerr << "Object " << argv[2] << " not callable" << std::endl;
    Py_Finalize();
    return 1;
  }

  auto n = argc - 3;
  auto args = PyTuple_New(n);
  for (int i = 0; i < n; ++i) {
    auto value = PyLong_FromLong(atoi(argv[i + 3]));
    if (!value) {
      PyErr_Print();
      std::cerr << "Cannot convert argument" << std::endl;
      Py_Finalize();
      return 1;
    }
    PyTuple_SetItem(args, i, value);
  }

  auto result = PyObject_CallObject(func, args);
  if (!result) {
    PyErr_Print();
    std::cerr << "Call failed" << std::endl;
    Py_Finalize();
    return 1;
  }

  std::cout << "CC: Result of call: " << PyLong_AsLong(result) << std::endl;

  Py_Finalize();
  return 0;
}
