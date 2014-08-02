#include <Python.h>

char source[] = "\
from cffi import FFI\n\
ffi = FFI()\n\
@ffi.callback('int(int)')\n\
def func(a):\n\
    print('Got from C \%d' \% a)\n\
    return a * 2\n\
ffi.cdef('int callback(int (*func)(int));')\n\
c_func = ffi.cast('int(*)(int(*)(int))', %d)\n\
c_func(func)\n\
print('finished the Python part')\n\
";

void callback(int (*func)(int)) {
    printf("Calling to Python, result: %d\n", func(3));
}

void Py_Execute_Source_Ptr(char* source, void* callback){
    char str[1024];
    sprintf(str, source, (int)callback);
    puts(str);
    PyRun_SimpleString(str);
}

int main() {
    Py_Initialize();
    Py_Execute_Source_Ptr(source, (void*) callback);
    Py_Finalize();
    return 0;
}
