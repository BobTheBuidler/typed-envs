#ifndef MYPYC_NATIVE_INTERNAL_303c4825a0ce575d88a6_H
#define MYPYC_NATIVE_INTERNAL_303c4825a0ce575d88a6_H
#include <Python.h>
#include <CPy.h>
#include "__native_303c4825a0ce575d88a6.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[77];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_typed_envs__internal;
extern CPyModule *CPyModule_typed_envs;
extern PyObject *CPyStatic_typed_envs___globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_typed_envs____env_var;
extern CPyModule *CPyModule_typed_envs___factory;
extern CPyModule *CPyModule_typed_envs___registry__internal;
extern CPyModule *CPyModule_typed_envs___registry;
extern CPyModule *CPyModule_typed_envs___typing__internal;
extern CPyModule *CPyModule_typed_envs___typing;
extern CPyModule *CPyModule_typed_envs____typed__internal;
extern CPyModule *CPyModule_typed_envs____typed;
extern PyObject *CPyStatic__typed___globals;
extern CPyModule *CPyModule_functools;
extern CPyModule *CPyModule_typed_envs___ENVIRONMENT_VARIABLES__internal;
extern CPyModule *CPyModule_typed_envs___ENVIRONMENT_VARIABLES;
extern PyObject *CPyStatic_ENVIRONMENT_VARIABLES___globals;
extern PyObject *CPyStatic_registry___globals;
extern PyObject *CPyStatic_typing___globals;
extern PyObject *CPyDef_typed_envs___create_env(PyObject *cpy_r_name, PyObject *cpy_r_typ, PyObject *cpy_r_default, PyObject *cpy_r_init_args, PyObject *cpy_r_string_converter, char cpy_r_verbose, PyObject *cpy_r_init_kwargs);
extern PyObject *CPyPy_typed_envs___create_env(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_typed_envs_____top_level__(void);
extern PyObject *CPyStatic__typed_____TYPED_CLS_DICT_CONSTANTS;
extern PyObject *CPyDef__typed___build_subclass(PyObject *cpy_r_type_arg);
extern PyObject *CPyPy__typed___build_subclass(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef__typed_____top_level__(void);
extern PyObject *CPyStatic_ENVIRONMENT_VARIABLES____factory;
extern PyObject *CPyStatic_ENVIRONMENT_VARIABLES___SHUTUP;
extern char CPyDef_ENVIRONMENT_VARIABLES_____top_level__(void);
extern PyObject *CPyStatic_registry___ENVIRONMENT;
extern PyObject *CPyStatic_registry____ENVIRONMENT_VARIABLES_SET_BY_USER;
extern PyObject *CPyStatic_registry____ENVIRONMENT_VARIABLES_USING_DEFAULTS;
extern char CPyDef_registry____register_new_env(PyObject *cpy_r_name, PyObject *cpy_r_instance);
extern PyObject *CPyPy_registry____register_new_env(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_registry_____top_level__(void);
extern char CPyDef_typing_____top_level__(void);
#endif
