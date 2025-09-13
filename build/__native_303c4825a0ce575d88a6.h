#ifndef MYPYC_NATIVE_303c4825a0ce575d88a6_H
#define MYPYC_NATIVE_303c4825a0ce575d88a6_H
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


struct export_table_303c4825a0ce575d88a6 {
    PyObject *(*CPyDef_typed_envs___create_env)(PyObject *cpy_r_name, PyObject *cpy_r_typ, PyObject *cpy_r_default, PyObject *cpy_r_init_args, PyObject *cpy_r_string_converter, char cpy_r_verbose, PyObject *cpy_r_init_kwargs);
    char (*CPyDef_typed_envs_____top_level__)(void);
    PyObject **CPyStatic__typed_____TYPED_CLS_DICT_CONSTANTS;
    PyObject *(*CPyDef__typed___build_subclass)(PyObject *cpy_r_type_arg);
    char (*CPyDef__typed_____top_level__)(void);
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES____factory;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___SHUTUP;
    char (*CPyDef_ENVIRONMENT_VARIABLES_____top_level__)(void);
    PyObject **CPyStatic_registry___ENVIRONMENT;
    PyObject **CPyStatic_registry____ENVIRONMENT_VARIABLES_SET_BY_USER;
    PyObject **CPyStatic_registry____ENVIRONMENT_VARIABLES_USING_DEFAULTS;
    char (*CPyDef_registry____register_new_env)(PyObject *cpy_r_name, PyObject *cpy_r_instance);
    char (*CPyDef_registry_____top_level__)(void);
    char (*CPyDef_typing_____top_level__)(void);
};
#endif
