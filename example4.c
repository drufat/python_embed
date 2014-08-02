#include <Python.h>
#include <stdio.h>

char source[] = \
"\
import cffi\n\
ffi = cffi.FFI()\n\
ffi.cdef('''\n\
struct Py {\n\
    double (*twice)(double);\n\
    char* (*md5)(char*);\n\
};\n\
''')\n\
\n\
import hashlib\n\
def md5(a):\n\
    return hashlib.md5(a).digest().encode('hex')\n\
\n\
def twice(a):\n\
    return a * 2\n\
\n\
c_py = ffi.cast('struct Py*', c_argument)\n\
def callback(name, f):\n\
    c_f = ffi.callback(ffi.typeof(getattr(c_py, name)), f)\n\
    setattr(c_py, name, c_f)\n\
callback('twice', twice)\n\
callback('md5', lambda x: ffi.new('char[]', md5(x)))\n\
";

struct Py {
    double (*twice)(double);
    char* (*md5)(char*);
};

int main()
{
    int res;
    struct Py py;

    rpython_startup_code();
    res = pypy_setup_home("/opt/pypy/lib_pypy", 1);
    if (res) {
        printf("Error setting pypy home!\n");
        return res;
    }

    res = pypy_execute_source_ptr(source, (void*)&py);
    if (res) {
        printf("Error calling pypy_execute_source_ptr!\n");
        return res;
    }

    {
        double x;
        x = 1.0; printf("twice(%f) = %f\n", x, py.twice(x));
        x = 2.0; printf("twice(%f) = %f\n", x, py.twice(x));
        x = 3.0; printf("twice(%f) = %f\n", x, py.twice(x));
    }

//    {
//        char* x;
//        x = "Hello, World!"; printf("md5(%s) = %s\n", x, py.md5(x));
//    }
}
