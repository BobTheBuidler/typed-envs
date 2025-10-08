#include <Python.h>

PyMODINIT_FUNC
PyInit_registry(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("303c4825a0ce575d88a6__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_typed_envs___registry");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "303c4825a0ce575d88a6__mypyc.init_typed_envs___registry");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_registry(); }
