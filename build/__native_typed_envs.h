#ifndef MYPYC_NATIVE_typed_envs_H
#define MYPYC_NATIVE_typed_envs_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T2OO
#define MYPYC_DECLARED_tuple_T2OO
typedef struct tuple_T2OO {
    PyObject *f0;
    PyObject *f1;
} tuple_T2OO;
#endif

#ifndef MYPYC_DECLARED_tuple_T3OOO
#define MYPYC_DECLARED_tuple_T3OOO
typedef struct tuple_T3OOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3OOO;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *___int__;
    PyObject *_type_arg;
    PyObject *_typed_cls_name;
    tuple_T2OO _typed_cls_bases;
    PyObject *_typed_cls_dict;
} typed_envs____typed___build_subclass_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} typed_envs____typed_____int___3_build_subclass_objObject;

#endif
