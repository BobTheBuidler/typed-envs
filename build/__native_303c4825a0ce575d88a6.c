#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "pythonsupport.c"
#include "__native_303c4825a0ce575d88a6.h"
#include "__native_internal_303c4825a0ce575d88a6.h"
static int typed_envs_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_typed_envs_internal, "__name__");
    CPyStatic_typed_envs___globals = PyModule_GetDict(CPyModule_typed_envs_internal);
    if (unlikely(CPyStatic_typed_envs___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_typed_envs_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_typed_envs_internal);
    Py_CLEAR(modname);
    return -1;
}
static PyMethodDef typed_envsmodule_methods[] = {
    {"create_env", (PyCFunction)CPyPy_typed_envs___create_env, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef typed_envsmodule = {
    PyModuleDef_HEAD_INIT,
    "typed_envs",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    typed_envsmodule_methods,
    NULL,
};

PyObject *CPyInit_typed_envs(void)
{
    if (CPyModule_typed_envs_internal) {
        Py_INCREF(CPyModule_typed_envs_internal);
        return CPyModule_typed_envs_internal;
    }
    CPyModule_typed_envs_internal = PyModule_Create(&typed_envsmodule);
    if (unlikely(CPyModule_typed_envs_internal == NULL))
        goto fail;
    if (typed_envs_exec(CPyModule_typed_envs_internal) != 0)
        goto fail;
    return CPyModule_typed_envs_internal;
    fail:
    return NULL;
}

PyObject *CPyDef_typed_envs___create_env(PyObject *cpy_r_name, PyObject *cpy_r_typ, PyObject *cpy_r_default, PyObject *cpy_r_init_args, PyObject *cpy_r_string_converter, char cpy_r_verbose, PyObject *cpy_r_init_kwargs) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    CPyPtr cpy_r_r7;
    CPyPtr cpy_r_r8;
    CPyPtr cpy_r_r9;
    CPyPtr cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    int32_t cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    if (cpy_r_string_converter != NULL) goto CPyL14;
    cpy_r_r0 = Py_None;
    cpy_r_string_converter = cpy_r_r0;
CPyL2: ;
    if (cpy_r_verbose != 2) goto CPyL4;
    cpy_r_verbose = 1;
CPyL4: ;
    cpy_r_r1 = CPyStatic_typed_envs___globals;
    cpy_r_r2 = CPyStatics[3]; /* 'default_factory' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "create_env", 104, CPyStatic_typed_envs___globals);
        goto CPyL15;
    }
    cpy_r_r4 = CPyStatics[4]; /* 'create_env' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "create_env", 104, CPyStatic_typed_envs___globals);
        goto CPyL15;
    }
    cpy_r_r6 = PyList_New(3);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "create_env", 104, CPyStatic_typed_envs___globals);
        goto CPyL16;
    }
    cpy_r_r7 = (CPyPtr)&((PyListObject *)cpy_r_r6)->ob_item;
    cpy_r_r8 = *(CPyPtr *)cpy_r_r7;
    CPy_INCREF(cpy_r_name);
    *(PyObject * *)cpy_r_r8 = cpy_r_name;
    CPy_INCREF(cpy_r_typ);
    cpy_r_r9 = cpy_r_r8 + 8;
    *(PyObject * *)cpy_r_r9 = cpy_r_typ;
    CPy_INCREF(cpy_r_default);
    cpy_r_r10 = cpy_r_r8 + 16;
    *(PyObject * *)cpy_r_r10 = cpy_r_default;
    cpy_r_r11 = CPyList_Extend(cpy_r_r6, cpy_r_init_args);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "create_env", 104, CPyStatic_typed_envs___globals);
        goto CPyL17;
    } else
        goto CPyL18;
CPyL8: ;
    cpy_r_r12 = CPyStatics[5]; /* 'string_converter' */
    cpy_r_r13 = CPyStatics[6]; /* 'verbose' */
    cpy_r_r14 = cpy_r_verbose ? Py_True : Py_False;
    cpy_r_r15 = CPyDict_Build(2, cpy_r_r12, cpy_r_string_converter, cpy_r_r13, cpy_r_r14);
    CPy_DECREF(cpy_r_string_converter);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "create_env", 104, CPyStatic_typed_envs___globals);
        goto CPyL19;
    }
    cpy_r_r16 = CPyDict_UpdateInDisplay(cpy_r_r15, cpy_r_init_kwargs);
    cpy_r_r17 = cpy_r_r16 >= 0;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("typed_envs/__init__.py", "create_env", 104, CPyStatic_typed_envs___globals);
        goto CPyL20;
    }
    cpy_r_r18 = PyList_AsTuple(cpy_r_r6);
    CPy_DECREF_NO_IMM(cpy_r_r6);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "create_env", 104, CPyStatic_typed_envs___globals);
        goto CPyL21;
    }
    cpy_r_r19 = PyObject_Call(cpy_r_r5, cpy_r_r18, cpy_r_r15);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r18);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "create_env", 104, CPyStatic_typed_envs___globals);
        goto CPyL13;
    }
    return cpy_r_r19;
CPyL13: ;
    cpy_r_r20 = NULL;
    return cpy_r_r20;
CPyL14: ;
    CPy_INCREF(cpy_r_string_converter);
    goto CPyL2;
CPyL15: ;
    CPy_DecRef(cpy_r_string_converter);
    goto CPyL13;
CPyL16: ;
    CPy_DecRef(cpy_r_string_converter);
    CPy_DecRef(cpy_r_r5);
    goto CPyL13;
CPyL17: ;
    CPy_DecRef(cpy_r_string_converter);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r6);
    goto CPyL13;
CPyL18: ;
    CPy_DECREF(cpy_r_r11);
    goto CPyL8;
CPyL19: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r6);
    goto CPyL13;
CPyL20: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r15);
    goto CPyL13;
CPyL21: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r15);
    goto CPyL13;
}

PyObject *CPyPy_typed_envs___create_env(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"name", "typ", "default", "string_converter", "verbose", 0};
    static CPyArg_Parser parser = {"%OOO|$OO:create_env", kwlist, 0};
    PyObject *obj_name;
    PyObject *obj_typ;
    PyObject *obj_default;
    PyObject *obj_init_args;
    PyObject *obj_string_converter = NULL;
    PyObject *obj_verbose = NULL;
    PyObject *obj_init_kwargs;
    if (!CPyArg_ParseStackAndKeywords(args, nargs, kwnames, &parser, &obj_init_args, &obj_init_kwargs, &obj_name, &obj_typ, &obj_default, &obj_string_converter, &obj_verbose)) {
        return NULL;
    }
    PyObject *arg_name;
    if (likely(PyUnicode_Check(obj_name)))
        arg_name = obj_name;
    else {
        CPy_TypeError("str", obj_name); 
        goto fail;
    }
    PyObject *arg_typ = obj_typ;
    PyObject *arg_default = obj_default;
    PyObject *arg_init_args = obj_init_args;
    PyObject *arg_string_converter;
    if (obj_string_converter == NULL) {
        arg_string_converter = NULL;
        goto __LL1;
    }
    arg_string_converter = obj_string_converter;
    if (arg_string_converter != NULL) goto __LL1;
    if (obj_string_converter == Py_None)
        arg_string_converter = obj_string_converter;
    else {
        arg_string_converter = NULL;
    }
    if (arg_string_converter != NULL) goto __LL1;
    CPy_TypeError("object or None", obj_string_converter); 
    goto fail;
__LL1: ;
    char arg_verbose;
    if (obj_verbose == NULL) {
        arg_verbose = 2;
    } else if (unlikely(!PyBool_Check(obj_verbose))) {
        CPy_TypeError("bool", obj_verbose); goto fail;
    } else
        arg_verbose = obj_verbose == Py_True;
    PyObject *arg_init_kwargs = obj_init_kwargs;
    PyObject *retval = CPyDef_typed_envs___create_env(arg_name, arg_typ, arg_default, arg_init_args, arg_string_converter, arg_verbose, arg_init_kwargs);
    CPy_DECREF(obj_init_args);
    CPy_DECREF(obj_init_kwargs);
    return retval;
fail: ;
    CPy_DECREF(obj_init_args);
    CPy_DECREF(obj_init_kwargs);
    CPy_AddTraceback("typed_envs/__init__.py", "create_env", 55, CPyStatic_typed_envs___globals);
    return NULL;
}

char CPyDef_typed_envs_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    int32_t cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    int32_t cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    int32_t cpy_r_r44;
    char cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    CPyPtr cpy_r_r52;
    CPyPtr cpy_r_r53;
    CPyPtr cpy_r_r54;
    CPyPtr cpy_r_r55;
    CPyPtr cpy_r_r56;
    CPyPtr cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    int32_t cpy_r_r60;
    char cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    char cpy_r_r68;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[7]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", -1, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[64]; /* ('Any', 'Optional', 'Type', 'TypeVar') */
    cpy_r_r6 = CPyStatics[12]; /* 'typing' */
    cpy_r_r7 = CPyStatic_typed_envs___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 1, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[65]; /* ('EnvironmentVariable',) */
    cpy_r_r10 = CPyStatics[14]; /* 'typed_envs._env_var' */
    cpy_r_r11 = CPyStatic_typed_envs___globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 3, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    CPyModule_typed_envs____env_var = cpy_r_r12;
    CPy_INCREF(CPyModule_typed_envs____env_var);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[66]; /* ('EnvVarFactory', 'logger', 'default_factory') */
    cpy_r_r14 = CPyStatics[17]; /* 'typed_envs.factory' */
    cpy_r_r15 = CPyStatic_typed_envs___globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 4, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    CPyModule_typed_envs___factory = cpy_r_r16;
    CPy_INCREF(CPyModule_typed_envs___factory);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[67]; /* ('ENVIRONMENT', '_ENVIRONMENT_VARIABLES_SET_BY_USER',
                                   '_ENVIRONMENT_VARIABLES_USING_DEFAULTS') */
    cpy_r_r18 = CPyStatics[21]; /* 'typed_envs.registry' */
    cpy_r_r19 = CPyStatic_typed_envs___globals;
    cpy_r_r20 = CPyImport_ImportFromMany(cpy_r_r18, cpy_r_r17, cpy_r_r17, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 5, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    CPyModule_typed_envs___registry = cpy_r_r20;
    CPy_INCREF(CPyModule_typed_envs___registry);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r21 = CPyStatics[68]; /* ('StringConverter',) */
    cpy_r_r22 = CPyStatics[23]; /* 'typed_envs.typing' */
    cpy_r_r23 = CPyStatic_typed_envs___globals;
    cpy_r_r24 = CPyImport_ImportFromMany(cpy_r_r22, cpy_r_r21, cpy_r_r21, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 10, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    CPyModule_typed_envs___typing = cpy_r_r24;
    CPy_INCREF(CPyModule_typed_envs___typing);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r25 = CPyStatics[24]; /* ('typed_envs is used to create specialized '
                                   '`EnvironmentVariable` objects that behave exactly the '
                                   'same as any other instance of the `typ` used to create '
                                   'them.\n'
                                   '\n'
                                   'typed_envs is used for:\n'
                                   '    - defining your envs in a readable, user friendly '
                                   'way\n'
                                   '    - enhancing type hints for the returned instances\n'
                                   '    - enhancing __repr__ of the returned instance with '
                                   'extra contextual information\n') */
    cpy_r_r26 = CPyStatic_typed_envs___globals;
    cpy_r_r27 = CPyStatics[25]; /* 'description' */
    cpy_r_r28 = CPyDict_SetItem(cpy_r_r26, cpy_r_r27, cpy_r_r25);
    cpy_r_r29 = cpy_r_r28 >= 0;
    if (unlikely(!cpy_r_r29)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 13, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    cpy_r_r30 = CPyStatics[26]; /* ('\n'
                                   'In the example below, `some_var` can be used just like '
                                   'as any other `int` object.\n'
                                   '\n'
                                   '```\n'
                                   'import typed_envs\n'
                                   'some_var = typed_envs.create_env("SET_WITH_THIS_ENV", '
                                   'int, 10)\n'
                                   '>>> isinstance(some_var, int)\n'
                                   'True\n'
                                   '>>> isinstance(some_var, EnvironmentVariable)\n'
                                   'True\n'
                                   '```\n'
                                   '\n'
                                   'There are only 2 differences between `some_var` and '
                                   '`int(10)`:\n'
                                   '    - `some_var` will properly type check as an '
                                   'instance of both `int` and `EnvironmentVariable`\n'
                                   '    - `some_var.__repr__()` will include contextual '
                                   'information about the `EnvironmentVariable`.\n'
                                   '\n'
                                   '```\n'
                                   '>>> some_var\n'
                                   '<EnvironmentVariable[name=`SET_WITH_THIS_ENV`, '
                                   'type=int, default_value=10, current_value=10, '
                                   'using_default=True]>\n'
                                   '>>> str(some_var)\n'
                                   '"10"\n'
                                   '>>> some_var + 5\n'
                                   '15\n'
                                   '>>> 20 / some_var\n'
                                   '2\n'
                                   '```\n'
                                   '\n') */
    cpy_r_r31 = CPyStatic_typed_envs___globals;
    cpy_r_r32 = CPyStatics[27]; /* 'description_addon' */
    cpy_r_r33 = CPyDict_SetItem(cpy_r_r31, cpy_r_r32, cpy_r_r30);
    cpy_r_r34 = cpy_r_r33 >= 0;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 22, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    cpy_r_r35 = CPyStatics[28]; /* 'T' */
    cpy_r_r36 = CPyStatic_typed_envs___globals;
    cpy_r_r37 = CPyStatics[11]; /* 'TypeVar' */
    cpy_r_r38 = CPyDict_GetItem(cpy_r_r36, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 52, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    PyObject *cpy_r_r39[1] = {cpy_r_r35};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = PyObject_Vectorcall(cpy_r_r38, cpy_r_r40, 1, 0);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 52, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    cpy_r_r42 = CPyStatic_typed_envs___globals;
    cpy_r_r43 = CPyStatics[28]; /* 'T' */
    cpy_r_r44 = CPyDict_SetItem(cpy_r_r42, cpy_r_r43, cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    cpy_r_r45 = cpy_r_r44 >= 0;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 52, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    cpy_r_r46 = CPyStatics[4]; /* 'create_env' */
    cpy_r_r47 = CPyStatics[15]; /* 'EnvVarFactory' */
    cpy_r_r48 = CPyStatics[18]; /* 'ENVIRONMENT' */
    cpy_r_r49 = CPyStatics[19]; /* '_ENVIRONMENT_VARIABLES_SET_BY_USER' */
    cpy_r_r50 = CPyStatics[20]; /* '_ENVIRONMENT_VARIABLES_USING_DEFAULTS' */
    cpy_r_r51 = PyList_New(5);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 115, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    cpy_r_r52 = (CPyPtr)&((PyListObject *)cpy_r_r51)->ob_item;
    cpy_r_r53 = *(CPyPtr *)cpy_r_r52;
    CPy_INCREF(cpy_r_r46);
    *(PyObject * *)cpy_r_r53 = cpy_r_r46;
    CPy_INCREF(cpy_r_r47);
    cpy_r_r54 = cpy_r_r53 + 8;
    *(PyObject * *)cpy_r_r54 = cpy_r_r47;
    CPy_INCREF(cpy_r_r48);
    cpy_r_r55 = cpy_r_r53 + 16;
    *(PyObject * *)cpy_r_r55 = cpy_r_r48;
    CPy_INCREF(cpy_r_r49);
    cpy_r_r56 = cpy_r_r53 + 24;
    *(PyObject * *)cpy_r_r56 = cpy_r_r49;
    CPy_INCREF(cpy_r_r50);
    cpy_r_r57 = cpy_r_r53 + 32;
    *(PyObject * *)cpy_r_r57 = cpy_r_r50;
    cpy_r_r58 = CPyStatic_typed_envs___globals;
    cpy_r_r59 = CPyStatics[29]; /* '__all__' */
    cpy_r_r60 = CPyDict_SetItem(cpy_r_r58, cpy_r_r59, cpy_r_r51);
    CPy_DECREF_NO_IMM(cpy_r_r51);
    cpy_r_r61 = cpy_r_r60 >= 0;
    if (unlikely(!cpy_r_r61)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 115, CPyStatic_typed_envs___globals);
        goto CPyL18;
    }
    cpy_r_r62 = CPyStatic_typed_envs___globals;
    cpy_r_r63 = CPyStatics[13]; /* 'EnvironmentVariable' */
    cpy_r_r64 = CPyDict_GetItem(cpy_r_r62, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 124, CPyStatic_typed_envs___globals);
        goto CPyL18;
    } else
        goto CPyL19;
CPyL16: ;
    cpy_r_r65 = CPyStatic_typed_envs___globals;
    cpy_r_r66 = CPyStatics[16]; /* 'logger' */
    cpy_r_r67 = CPyDict_GetItem(cpy_r_r65, cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("typed_envs/__init__.py", "<module>", 125, CPyStatic_typed_envs___globals);
        goto CPyL18;
    } else
        goto CPyL20;
CPyL17: ;
    return 1;
CPyL18: ;
    cpy_r_r68 = 2;
    return cpy_r_r68;
CPyL19: ;
    CPy_DECREF(cpy_r_r64);
    goto CPyL16;
CPyL20: ;
    CPy_DECREF(cpy_r_r67);
    goto CPyL17;
}
static int _typed_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_typed_envs____typed_internal, "__name__");
    CPyStatic__typed___globals = PyModule_GetDict(CPyModule_typed_envs____typed_internal);
    if (unlikely(CPyStatic__typed___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef__typed_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_typed_envs____typed_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic__typed_____TYPED_CLS_DICT_CONSTANTS);
    CPyStatic__typed_____TYPED_CLS_DICT_CONSTANTS = NULL;
    return -1;
}
static PyMethodDef _typedmodule_methods[] = {
    {"build_subclass", (PyCFunction)CPyPy__typed___build_subclass, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _typedmodule = {
    PyModuleDef_HEAD_INIT,
    "typed_envs._typed",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    _typedmodule_methods,
    NULL,
};

PyObject *CPyInit_typed_envs____typed(void)
{
    if (CPyModule_typed_envs____typed_internal) {
        Py_INCREF(CPyModule_typed_envs____typed_internal);
        return CPyModule_typed_envs____typed_internal;
    }
    CPyModule_typed_envs____typed_internal = PyModule_Create(&_typedmodule);
    if (unlikely(CPyModule_typed_envs____typed_internal == NULL))
        goto fail;
    if (_typed_exec(CPyModule_typed_envs____typed_internal) != 0)
        goto fail;
    return CPyModule_typed_envs____typed_internal;
    fail:
    return NULL;
}

PyObject *CPyDef__typed___build_subclass(PyObject *cpy_r_type_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    tuple_T2OO cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    int32_t cpy_r_r33;
    char cpy_r_r34;
    int32_t cpy_r_r35;
    char cpy_r_r36;
    int32_t cpy_r_r37;
    char cpy_r_r38;
    int32_t cpy_r_r39;
    char cpy_r_r40;
    int32_t cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    char cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    int32_t cpy_r_r49;
    char cpy_r_r50;
    PyObject *cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    int32_t cpy_r_r56;
    char cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject **cpy_r_r61;
    PyObject *cpy_r_r62;
    tuple_T3OOO cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject **cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    int32_t cpy_r_r93;
    char cpy_r_r94;
    int32_t cpy_r_r95;
    char cpy_r_r96;
    int32_t cpy_r_r97;
    char cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    char cpy_r_r102;
    PyObject *cpy_r_r103;
    cpy_r_r0 = CPyStatics[30]; /* 'EnvironmentVariable[' */
    cpy_r_r1 = CPyStatics[31]; /* '__name__' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_type_arg, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 26, CPyStatic__typed___globals);
        goto CPyL58;
    }
    if (likely(PyUnicode_Check(cpy_r_r2)))
        cpy_r_r3 = cpy_r_r2;
    else {
        CPy_TypeErrorTraceback("typed_envs/_typed.py", "build_subclass", 26, CPyStatic__typed___globals, "str", cpy_r_r2);
        goto CPyL58;
    }
    cpy_r_r4 = CPyStatics[32]; /* ']' */
    cpy_r_r5 = CPyStr_Build(3, cpy_r_r0, cpy_r_r3, cpy_r_r4);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 26, CPyStatic__typed___globals);
        goto CPyL58;
    }
    cpy_r_r6 = (PyObject *)&PyBool_Type;
    cpy_r_r7 = cpy_r_type_arg == cpy_r_r6;
    if (!cpy_r_r7) goto CPyL5;
    cpy_r_r8 = (PyObject *)&PyLong_Type;
    CPy_INCREF(cpy_r_r8);
    cpy_r_r9 = cpy_r_r8;
    goto CPyL6;
CPyL5: ;
    CPy_INCREF(cpy_r_type_arg);
    cpy_r_r9 = cpy_r_type_arg;
CPyL6: ;
    cpy_r_r10 = CPyStatic__typed___globals;
    cpy_r_r11 = CPyStatics[13]; /* 'EnvironmentVariable' */
    cpy_r_r12 = CPyDict_GetItem(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 27, CPyStatic__typed___globals);
        goto CPyL59;
    }
    cpy_r_r13.f0 = cpy_r_r9;
    cpy_r_r13.f1 = cpy_r_r12;
    cpy_r_r14 = CPyStatic__typed_____TYPED_CLS_DICT_CONSTANTS;
    if (unlikely(cpy_r_r14 == NULL)) {
        goto CPyL60;
    } else
        goto CPyL10;
CPyL8: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"__TYPED_CLS_DICT_CONSTANTS\" was not set");
    cpy_r_r15 = 0;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 29, CPyStatic__typed___globals);
        goto CPyL58;
    }
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r16 = CPyStatics[33]; /* '__args__' */
    cpy_r_r17 = CPyStatics[34]; /* '__module__' */
    cpy_r_r18 = CPyStatics[34]; /* '__module__' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_type_arg, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 31, CPyStatic__typed___globals);
        goto CPyL61;
    }
    if (likely(PyUnicode_Check(cpy_r_r19)))
        cpy_r_r20 = cpy_r_r19;
    else {
        CPy_TypeErrorTraceback("typed_envs/_typed.py", "build_subclass", 31, CPyStatic__typed___globals, "str", cpy_r_r19);
        goto CPyL61;
    }
    cpy_r_r21 = CPyStatics[35]; /* '__qualname__' */
    cpy_r_r22 = CPyStatics[30]; /* 'EnvironmentVariable[' */
    cpy_r_r23 = CPyStatics[35]; /* '__qualname__' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_type_arg, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 32, CPyStatic__typed___globals);
        goto CPyL62;
    }
    if (likely(PyUnicode_Check(cpy_r_r24)))
        cpy_r_r25 = cpy_r_r24;
    else {
        CPy_TypeErrorTraceback("typed_envs/_typed.py", "build_subclass", 32, CPyStatic__typed___globals, "str", cpy_r_r24);
        goto CPyL62;
    }
    cpy_r_r26 = CPyStatics[32]; /* ']' */
    cpy_r_r27 = CPyStr_Build(3, cpy_r_r22, cpy_r_r25, cpy_r_r26);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 32, CPyStatic__typed___globals);
        goto CPyL62;
    }
    cpy_r_r28 = CPyStatics[36]; /* '__doc__' */
    cpy_r_r29 = CPyStatics[36]; /* '__doc__' */
    cpy_r_r30 = CPyObject_GetAttr(cpy_r_type_arg, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 33, CPyStatic__typed___globals);
        goto CPyL63;
    }
    if (PyUnicode_Check(cpy_r_r30))
        cpy_r_r31 = cpy_r_r30;
    else {
        cpy_r_r31 = NULL;
    }
    if (cpy_r_r31 != NULL) goto __LL2;
    if (cpy_r_r30 == Py_None)
        cpy_r_r31 = cpy_r_r30;
    else {
        cpy_r_r31 = NULL;
    }
    if (cpy_r_r31 != NULL) goto __LL2;
    CPy_TypeErrorTraceback("typed_envs/_typed.py", "build_subclass", 33, CPyStatic__typed___globals, "str or None", cpy_r_r30);
    goto CPyL63;
__LL2: ;
    cpy_r_r32 = PyDict_New();
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 28, CPyStatic__typed___globals);
        goto CPyL64;
    }
    cpy_r_r33 = CPyDict_UpdateInDisplay(cpy_r_r32, cpy_r_r14);
    cpy_r_r34 = cpy_r_r33 >= 0;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 28, CPyStatic__typed___globals);
        goto CPyL65;
    }
    cpy_r_r35 = CPyDict_SetItem(cpy_r_r32, cpy_r_r16, cpy_r_type_arg);
    cpy_r_r36 = cpy_r_r35 >= 0;
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 28, CPyStatic__typed___globals);
        goto CPyL65;
    }
    cpy_r_r37 = CPyDict_SetItem(cpy_r_r32, cpy_r_r17, cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r38 = cpy_r_r37 >= 0;
    if (unlikely(!cpy_r_r38)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 28, CPyStatic__typed___globals);
        goto CPyL66;
    }
    cpy_r_r39 = CPyDict_SetItem(cpy_r_r32, cpy_r_r21, cpy_r_r27);
    CPy_DECREF(cpy_r_r27);
    cpy_r_r40 = cpy_r_r39 >= 0;
    if (unlikely(!cpy_r_r40)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 28, CPyStatic__typed___globals);
        goto CPyL67;
    }
    cpy_r_r41 = CPyDict_SetItem(cpy_r_r32, cpy_r_r28, cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    cpy_r_r42 = cpy_r_r41 >= 0;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 28, CPyStatic__typed___globals);
        goto CPyL68;
    }
    cpy_r_r43 = CPyStatics[37]; /* '__annotations__' */
    cpy_r_r44 = PyObject_HasAttr(cpy_r_type_arg, cpy_r_r43);
    if (!cpy_r_r44) goto CPyL27;
    cpy_r_r45 = CPyStatics[37]; /* '__annotations__' */
    cpy_r_r46 = CPyObject_GetAttr(cpy_r_type_arg, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 36, CPyStatic__typed___globals);
        goto CPyL69;
    }
    if (likely(PyDict_Check(cpy_r_r46)))
        cpy_r_r47 = cpy_r_r46;
    else {
        CPy_TypeErrorTraceback("typed_envs/_typed.py", "build_subclass", 36, CPyStatic__typed___globals, "dict", cpy_r_r46);
        goto CPyL69;
    }
    cpy_r_r48 = CPyStatics[37]; /* '__annotations__' */
    cpy_r_r49 = CPyDict_SetItem(cpy_r_r32, cpy_r_r48, cpy_r_r47);
    CPy_DECREF(cpy_r_r47);
    cpy_r_r50 = cpy_r_r49 >= 0;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 36, CPyStatic__typed___globals);
        goto CPyL69;
    }
CPyL27: ;
    cpy_r_r51 = CPyStatics[38]; /* '__parameters__' */
    cpy_r_r52 = PyObject_HasAttr(cpy_r_type_arg, cpy_r_r51);
    if (!cpy_r_r52) goto CPyL30;
    cpy_r_r53 = CPyStatics[38]; /* '__parameters__' */
    cpy_r_r54 = CPyObject_GetAttr(cpy_r_type_arg, cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 38, CPyStatic__typed___globals);
        goto CPyL69;
    }
    cpy_r_r55 = CPyStatics[38]; /* '__parameters__' */
    cpy_r_r56 = CPyDict_SetItem(cpy_r_r32, cpy_r_r55, cpy_r_r54);
    CPy_DECREF(cpy_r_r54);
    cpy_r_r57 = cpy_r_r56 >= 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 38, CPyStatic__typed___globals);
        goto CPyL69;
    }
CPyL30: ;
    cpy_r_r58 = (PyObject *)&PyType_Type;
    CPy_INCREF(cpy_r_r13.f0);
    CPy_INCREF(cpy_r_r13.f1);
    cpy_r_r59 = PyTuple_New(2);
    if (unlikely(cpy_r_r59 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp3 = cpy_r_r13.f0;
    PyTuple_SET_ITEM(cpy_r_r59, 0, __tmp3);
    PyObject *__tmp4 = cpy_r_r13.f1;
    PyTuple_SET_ITEM(cpy_r_r59, 1, __tmp4);
    PyObject *cpy_r_r60[3] = {cpy_r_r5, cpy_r_r59, cpy_r_r32};
    cpy_r_r61 = (PyObject **)&cpy_r_r60;
    cpy_r_r62 = PyObject_Vectorcall(cpy_r_r58, cpy_r_r61, 3, 0);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 41, CPyStatic__typed___globals);
        goto CPyL70;
    } else
        goto CPyL71;
CPyL31: ;
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r59);
    CPy_DECREF(cpy_r_r32);
    return cpy_r_r62;
CPyL32: ;
    cpy_r_r63 = CPy_CatchError();
    cpy_r_r64 = CPyModule_builtins;
    cpy_r_r65 = CPyStatics[39]; /* 'TypeError' */
    cpy_r_r66 = CPyObject_GetAttr(cpy_r_r64, cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 42, CPyStatic__typed___globals);
        goto CPyL72;
    }
    cpy_r_r67 = CPy_ExceptionMatches(cpy_r_r66);
    CPy_DecRef(cpy_r_r66);
    if (!cpy_r_r67) goto CPyL73;
    cpy_r_r68 = CPy_GetExcValue();
    cpy_r_r69 = CPyStatics[40]; /* 'args' */
    cpy_r_r70 = CPyObject_GetAttr(cpy_r_r68, cpy_r_r69);
    CPy_DecRef(cpy_r_r68);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 44, CPyStatic__typed___globals);
        goto CPyL72;
    }
    if (likely(PyTuple_Check(cpy_r_r70)))
        cpy_r_r71 = cpy_r_r70;
    else {
        CPy_TypeErrorTraceback("typed_envs/_typed.py", "build_subclass", 44, CPyStatic__typed___globals, "tuple", cpy_r_r70);
        goto CPyL72;
    }
    cpy_r_r72 = CPyStatics[41]; /* 'bases: ' */
    CPy_INCREF(cpy_r_r13.f0);
    CPy_INCREF(cpy_r_r13.f1);
    cpy_r_r73 = PyTuple_New(2);
    if (unlikely(cpy_r_r73 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp5 = cpy_r_r13.f0;
    PyTuple_SET_ITEM(cpy_r_r73, 0, __tmp5);
    PyObject *__tmp6 = cpy_r_r13.f1;
    PyTuple_SET_ITEM(cpy_r_r73, 1, __tmp6);
    cpy_r_r74 = PyObject_Str(cpy_r_r73);
    CPy_DecRef(cpy_r_r73);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 46, CPyStatic__typed___globals);
        goto CPyL74;
    }
    cpy_r_r75 = CPyStr_Build(2, cpy_r_r72, cpy_r_r74);
    CPy_DecRef(cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 46, CPyStatic__typed___globals);
        goto CPyL74;
    }
    cpy_r_r76 = CPyStatics[42]; /* 'typed: ' */
    cpy_r_r77 = (PyObject *)&PyType_Type;
    cpy_r_r78 = CPyModule_builtins;
    cpy_r_r79 = CPyStatics[43]; /* 'map' */
    cpy_r_r80 = CPyObject_GetAttr(cpy_r_r78, cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 47, CPyStatic__typed___globals);
        goto CPyL75;
    }
    cpy_r_r81 = PyTuple_New(2);
    if (unlikely(cpy_r_r81 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp7 = cpy_r_r13.f0;
    PyTuple_SET_ITEM(cpy_r_r81, 0, __tmp7);
    PyObject *__tmp8 = cpy_r_r13.f1;
    PyTuple_SET_ITEM(cpy_r_r81, 1, __tmp8);
    PyObject *cpy_r_r82[2] = {cpy_r_r77, cpy_r_r81};
    cpy_r_r83 = (PyObject **)&cpy_r_r82;
    cpy_r_r84 = PyObject_Vectorcall(cpy_r_r80, cpy_r_r83, 2, 0);
    CPy_DecRef(cpy_r_r80);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 47, CPyStatic__typed___globals);
        goto CPyL76;
    }
    CPy_DecRef(cpy_r_r81);
    cpy_r_r85 = PySequence_Tuple(cpy_r_r84);
    CPy_DecRef(cpy_r_r84);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 47, CPyStatic__typed___globals);
        goto CPyL77;
    }
    cpy_r_r86 = PyObject_Str(cpy_r_r85);
    CPy_DecRef(cpy_r_r85);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 47, CPyStatic__typed___globals);
        goto CPyL77;
    }
    cpy_r_r87 = CPyStr_Build(2, cpy_r_r76, cpy_r_r86);
    CPy_DecRef(cpy_r_r86);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 47, CPyStatic__typed___globals);
        goto CPyL77;
    }
    cpy_r_r88 = CPyModule_builtins;
    cpy_r_r89 = CPyStatics[39]; /* 'TypeError' */
    cpy_r_r90 = CPyObject_GetAttr(cpy_r_r88, cpy_r_r89);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 43, CPyStatic__typed___globals);
        goto CPyL78;
    }
    cpy_r_r91 = PyList_New(0);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 43, CPyStatic__typed___globals);
        goto CPyL79;
    }
    cpy_r_r92 = CPyList_Extend(cpy_r_r91, cpy_r_r71);
    CPy_DecRef(cpy_r_r71);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 43, CPyStatic__typed___globals);
        goto CPyL80;
    } else
        goto CPyL81;
CPyL46: ;
    cpy_r_r93 = PyList_Append(cpy_r_r91, cpy_r_r5);
    CPy_DecRef(cpy_r_r5);
    cpy_r_r94 = cpy_r_r93 >= 0;
    if (unlikely(!cpy_r_r94)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 43, CPyStatic__typed___globals);
        goto CPyL82;
    }
    cpy_r_r95 = PyList_Append(cpy_r_r91, cpy_r_r75);
    CPy_DecRef(cpy_r_r75);
    cpy_r_r96 = cpy_r_r95 >= 0;
    if (unlikely(!cpy_r_r96)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 43, CPyStatic__typed___globals);
        goto CPyL83;
    }
    cpy_r_r97 = PyList_Append(cpy_r_r91, cpy_r_r87);
    CPy_DecRef(cpy_r_r87);
    cpy_r_r98 = cpy_r_r97 >= 0;
    if (unlikely(!cpy_r_r98)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 43, CPyStatic__typed___globals);
        goto CPyL84;
    }
    cpy_r_r99 = PyList_AsTuple(cpy_r_r91);
    CPy_DecRef(cpy_r_r91);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 43, CPyStatic__typed___globals);
        goto CPyL85;
    }
    cpy_r_r100 = PyDict_New();
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 43, CPyStatic__typed___globals);
        goto CPyL86;
    }
    cpy_r_r101 = PyObject_Call(cpy_r_r90, cpy_r_r99, cpy_r_r100);
    CPy_DecRef(cpy_r_r90);
    CPy_DecRef(cpy_r_r99);
    CPy_DecRef(cpy_r_r100);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 43, CPyStatic__typed___globals);
        goto CPyL56;
    }
    CPy_Raise(cpy_r_r101);
    CPy_DecRef(cpy_r_r101);
    if (unlikely(!0)) {
        CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 43, CPyStatic__typed___globals);
        goto CPyL56;
    } else
        goto CPyL87;
CPyL53: ;
    CPy_Unreachable();
CPyL54: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL56;
    } else
        goto CPyL88;
CPyL55: ;
    CPy_Unreachable();
CPyL56: ;
    CPy_RestoreExcInfo(cpy_r_r63);
    CPy_DecRef(cpy_r_r63.f0);
    CPy_DecRef(cpy_r_r63.f1);
    CPy_DecRef(cpy_r_r63.f2);
    cpy_r_r102 = CPy_KeepPropagating();
    if (!cpy_r_r102) goto CPyL58;
    CPy_Unreachable();
CPyL58: ;
    cpy_r_r103 = NULL;
    return cpy_r_r103;
CPyL59: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r9);
    goto CPyL58;
CPyL60: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    goto CPyL8;
CPyL61: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    goto CPyL58;
CPyL62: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r20);
    goto CPyL58;
CPyL63: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r27);
    goto CPyL58;
CPyL64: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r27);
    CPy_DecRef(cpy_r_r31);
    goto CPyL58;
CPyL65: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r27);
    CPy_DecRef(cpy_r_r31);
    CPy_DecRef(cpy_r_r32);
    goto CPyL58;
CPyL66: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r27);
    CPy_DecRef(cpy_r_r31);
    CPy_DecRef(cpy_r_r32);
    goto CPyL58;
CPyL67: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r31);
    CPy_DecRef(cpy_r_r32);
    goto CPyL58;
CPyL68: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r32);
    goto CPyL58;
CPyL69: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r32);
    goto CPyL58;
CPyL70: ;
    CPy_DecRef(cpy_r_r32);
    CPy_DecRef(cpy_r_r59);
    goto CPyL32;
CPyL71: ;
    CPy_DECREF(cpy_r_r13.f0);
    CPy_DECREF(cpy_r_r13.f1);
    goto CPyL31;
CPyL72: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    goto CPyL56;
CPyL73: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    goto CPyL54;
CPyL74: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r71);
    goto CPyL56;
CPyL75: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r71);
    CPy_DecRef(cpy_r_r75);
    goto CPyL56;
CPyL76: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r71);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r81);
    goto CPyL56;
CPyL77: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r71);
    CPy_DecRef(cpy_r_r75);
    goto CPyL56;
CPyL78: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r71);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r87);
    goto CPyL56;
CPyL79: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r71);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r87);
    CPy_DecRef(cpy_r_r90);
    goto CPyL56;
CPyL80: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r87);
    CPy_DecRef(cpy_r_r90);
    CPy_DecRef(cpy_r_r91);
    goto CPyL56;
CPyL81: ;
    CPy_DecRef(cpy_r_r92);
    goto CPyL46;
CPyL82: ;
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r87);
    CPy_DecRef(cpy_r_r90);
    CPy_DecRef(cpy_r_r91);
    goto CPyL56;
CPyL83: ;
    CPy_DecRef(cpy_r_r87);
    CPy_DecRef(cpy_r_r90);
    CPy_DecRef(cpy_r_r91);
    goto CPyL56;
CPyL84: ;
    CPy_DecRef(cpy_r_r90);
    CPy_DecRef(cpy_r_r91);
    goto CPyL56;
CPyL85: ;
    CPy_DecRef(cpy_r_r90);
    goto CPyL56;
CPyL86: ;
    CPy_DecRef(cpy_r_r90);
    CPy_DecRef(cpy_r_r99);
    goto CPyL56;
CPyL87: ;
    CPy_DecRef(cpy_r_r63.f0);
    CPy_DecRef(cpy_r_r63.f1);
    CPy_DecRef(cpy_r_r63.f2);
    goto CPyL53;
CPyL88: ;
    CPy_DecRef(cpy_r_r63.f0);
    CPy_DecRef(cpy_r_r63.f1);
    CPy_DecRef(cpy_r_r63.f2);
    goto CPyL55;
}

PyObject *CPyPy__typed___build_subclass(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"type_arg", 0};
    static CPyArg_Parser parser = {"O:build_subclass", kwlist, 0};
    PyObject *obj_type_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_type_arg)) {
        return NULL;
    }
    PyObject *arg_type_arg = obj_type_arg;
    PyObject *retval = CPyDef__typed___build_subclass(arg_type_arg);
    return retval;
fail: ;
    CPy_AddTraceback("typed_envs/_typed.py", "build_subclass", 18, CPyStatic__typed___globals);
    return NULL;
}

char CPyDef__typed_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    int32_t cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    int32_t cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject **cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject **cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    int32_t cpy_r_r65;
    char cpy_r_r66;
    char cpy_r_r67;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[7]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", -1, CPyStatic__typed___globals);
        goto CPyL22;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[69]; /* ('lru_cache',) */
    cpy_r_r6 = CPyStatics[45]; /* 'functools' */
    cpy_r_r7 = CPyStatic__typed___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 1, CPyStatic__typed___globals);
        goto CPyL22;
    }
    CPyModule_functools = cpy_r_r8;
    CPy_INCREF(CPyModule_functools);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[70]; /* ('Final', 'Type', 'TypeVar') */
    cpy_r_r10 = CPyStatics[12]; /* 'typing' */
    cpy_r_r11 = CPyStatic__typed___globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 2, CPyStatic__typed___globals);
        goto CPyL22;
    }
    CPyModule_typing = cpy_r_r12;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[65]; /* ('EnvironmentVariable',) */
    cpy_r_r14 = CPyStatics[14]; /* 'typed_envs._env_var' */
    cpy_r_r15 = CPyStatic__typed___globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 4, CPyStatic__typed___globals);
        goto CPyL22;
    }
    CPyModule_typed_envs____env_var = cpy_r_r16;
    CPy_INCREF(CPyModule_typed_envs____env_var);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[28]; /* 'T' */
    cpy_r_r18 = CPyStatic__typed___globals;
    cpy_r_r19 = CPyStatics[11]; /* 'TypeVar' */
    cpy_r_r20 = CPyDict_GetItem(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 7, CPyStatic__typed___globals);
        goto CPyL22;
    }
    PyObject *cpy_r_r21[1] = {cpy_r_r17};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = PyObject_Vectorcall(cpy_r_r20, cpy_r_r22, 1, 0);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 7, CPyStatic__typed___globals);
        goto CPyL22;
    }
    cpy_r_r24 = CPyStatic__typed___globals;
    cpy_r_r25 = CPyStatics[28]; /* 'T' */
    cpy_r_r26 = CPyDict_SetItem(cpy_r_r24, cpy_r_r25, cpy_r_r23);
    CPy_DECREF(cpy_r_r23);
    cpy_r_r27 = cpy_r_r26 >= 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 7, CPyStatic__typed___globals);
        goto CPyL22;
    }
    cpy_r_r28 = CPyStatics[47]; /* '__repr__' */
    cpy_r_r29 = CPyStatic__typed___globals;
    cpy_r_r30 = CPyStatics[13]; /* 'EnvironmentVariable' */
    cpy_r_r31 = CPyDict_GetItem(cpy_r_r29, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 11, CPyStatic__typed___globals);
        goto CPyL22;
    }
    cpy_r_r32 = CPyStatics[47]; /* '__repr__' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_r31, cpy_r_r32);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 11, CPyStatic__typed___globals);
        goto CPyL22;
    }
    cpy_r_r34 = CPyStatics[48]; /* '__str__' */
    cpy_r_r35 = CPyStatic__typed___globals;
    cpy_r_r36 = CPyStatics[13]; /* 'EnvironmentVariable' */
    cpy_r_r37 = CPyDict_GetItem(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 12, CPyStatic__typed___globals);
        goto CPyL23;
    }
    cpy_r_r38 = CPyStatics[48]; /* '__str__' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 12, CPyStatic__typed___globals);
        goto CPyL23;
    }
    cpy_r_r40 = CPyStatics[49]; /* '__origin__' */
    cpy_r_r41 = CPyStatic__typed___globals;
    cpy_r_r42 = CPyStatics[13]; /* 'EnvironmentVariable' */
    cpy_r_r43 = CPyDict_GetItem(cpy_r_r41, cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 13, CPyStatic__typed___globals);
        goto CPyL24;
    }
    cpy_r_r44 = CPyDict_Build(3, cpy_r_r28, cpy_r_r33, cpy_r_r34, cpy_r_r39, cpy_r_r40, cpy_r_r43);
    CPy_DECREF(cpy_r_r33);
    CPy_DECREF(cpy_r_r39);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 10, CPyStatic__typed___globals);
        goto CPyL22;
    }
    CPyStatic__typed_____TYPED_CLS_DICT_CONSTANTS = cpy_r_r44;
    CPy_INCREF(CPyStatic__typed_____TYPED_CLS_DICT_CONSTANTS);
    cpy_r_r45 = CPyStatic__typed___globals;
    cpy_r_r46 = CPyStatics[50]; /* '__TYPED_CLS_DICT_CONSTANTS' */
    cpy_r_r47 = CPyDict_SetItem(cpy_r_r45, cpy_r_r46, cpy_r_r44);
    CPy_DECREF(cpy_r_r44);
    cpy_r_r48 = cpy_r_r47 >= 0;
    if (unlikely(!cpy_r_r48)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 10, CPyStatic__typed___globals);
        goto CPyL22;
    }
    cpy_r_r49 = CPyStatic__typed___globals;
    cpy_r_r50 = CPyStatics[51]; /* 'build_subclass' */
    cpy_r_r51 = CPyDict_GetItem(cpy_r_r49, cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 17, CPyStatic__typed___globals);
        goto CPyL22;
    }
    cpy_r_r52 = CPyStatic__typed___globals;
    cpy_r_r53 = CPyStatics[44]; /* 'lru_cache' */
    cpy_r_r54 = CPyDict_GetItem(cpy_r_r52, cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 17, CPyStatic__typed___globals);
        goto CPyL25;
    }
    cpy_r_r55 = Py_None;
    PyObject *cpy_r_r56[1] = {cpy_r_r55};
    cpy_r_r57 = (PyObject **)&cpy_r_r56;
    cpy_r_r58 = CPyStatics[71]; /* ('maxsize',) */
    cpy_r_r59 = PyObject_Vectorcall(cpy_r_r54, cpy_r_r57, 0, cpy_r_r58);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 17, CPyStatic__typed___globals);
        goto CPyL25;
    }
    PyObject *cpy_r_r60[1] = {cpy_r_r51};
    cpy_r_r61 = (PyObject **)&cpy_r_r60;
    cpy_r_r62 = PyObject_Vectorcall(cpy_r_r59, cpy_r_r61, 1, 0);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 17, CPyStatic__typed___globals);
        goto CPyL25;
    }
    CPy_DECREF(cpy_r_r51);
    cpy_r_r63 = CPyStatic__typed___globals;
    cpy_r_r64 = CPyStatics[51]; /* 'build_subclass' */
    cpy_r_r65 = CPyDict_SetItem(cpy_r_r63, cpy_r_r64, cpy_r_r62);
    CPy_DECREF(cpy_r_r62);
    cpy_r_r66 = cpy_r_r65 >= 0;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("typed_envs/_typed.py", "<module>", 17, CPyStatic__typed___globals);
        goto CPyL22;
    }
    return 1;
CPyL22: ;
    cpy_r_r67 = 2;
    return cpy_r_r67;
CPyL23: ;
    CPy_DecRef(cpy_r_r33);
    goto CPyL22;
CPyL24: ;
    CPy_DecRef(cpy_r_r33);
    CPy_DecRef(cpy_r_r39);
    goto CPyL22;
CPyL25: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL22;
}
static int ENVIRONMENT_VARIABLES_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_typed_envs___ENVIRONMENT_VARIABLES_internal, "__name__");
    CPyStatic_ENVIRONMENT_VARIABLES___globals = PyModule_GetDict(CPyModule_typed_envs___ENVIRONMENT_VARIABLES_internal);
    if (unlikely(CPyStatic_ENVIRONMENT_VARIABLES___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_ENVIRONMENT_VARIABLES_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_typed_envs___ENVIRONMENT_VARIABLES_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic_ENVIRONMENT_VARIABLES____factory);
    CPyStatic_ENVIRONMENT_VARIABLES____factory = NULL;
    CPy_XDECREF(CPyStatic_ENVIRONMENT_VARIABLES___SHUTUP);
    CPyStatic_ENVIRONMENT_VARIABLES___SHUTUP = NULL;
    return -1;
}
static PyMethodDef ENVIRONMENT_VARIABLESmodule_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef ENVIRONMENT_VARIABLESmodule = {
    PyModuleDef_HEAD_INIT,
    "typed_envs.ENVIRONMENT_VARIABLES",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    ENVIRONMENT_VARIABLESmodule_methods,
    NULL,
};

PyObject *CPyInit_typed_envs___ENVIRONMENT_VARIABLES(void)
{
    if (CPyModule_typed_envs___ENVIRONMENT_VARIABLES_internal) {
        Py_INCREF(CPyModule_typed_envs___ENVIRONMENT_VARIABLES_internal);
        return CPyModule_typed_envs___ENVIRONMENT_VARIABLES_internal;
    }
    CPyModule_typed_envs___ENVIRONMENT_VARIABLES_internal = PyModule_Create(&ENVIRONMENT_VARIABLESmodule);
    if (unlikely(CPyModule_typed_envs___ENVIRONMENT_VARIABLES_internal == NULL))
        goto fail;
    if (ENVIRONMENT_VARIABLES_exec(CPyModule_typed_envs___ENVIRONMENT_VARIABLES_internal) != 0)
        goto fail;
    return CPyModule_typed_envs___ENVIRONMENT_VARIABLES_internal;
    fail:
    return NULL;
}

char CPyDef_ENVIRONMENT_VARIABLES_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject **cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    int32_t cpy_r_r37;
    char cpy_r_r38;
    char cpy_r_r39;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[7]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("typed_envs/ENVIRONMENT_VARIABLES.py", "<module>", -1, CPyStatic_ENVIRONMENT_VARIABLES___globals);
        goto CPyL15;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[72]; /* ('TYPE_CHECKING', 'Final') */
    cpy_r_r6 = CPyStatics[12]; /* 'typing' */
    cpy_r_r7 = CPyStatic_ENVIRONMENT_VARIABLES___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("typed_envs/ENVIRONMENT_VARIABLES.py", "<module>", 6, CPyStatic_ENVIRONMENT_VARIABLES___globals);
        goto CPyL15;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[73]; /* ('EnvVarFactory',) */
    cpy_r_r10 = CPyStatics[17]; /* 'typed_envs.factory' */
    cpy_r_r11 = CPyStatic_ENVIRONMENT_VARIABLES___globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("typed_envs/ENVIRONMENT_VARIABLES.py", "<module>", 8, CPyStatic_ENVIRONMENT_VARIABLES___globals);
        goto CPyL15;
    }
    CPyModule_typed_envs___factory = cpy_r_r12;
    CPy_INCREF(CPyModule_typed_envs___factory);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[54]; /* 'TYPEDENVS' */
    cpy_r_r14 = CPyStatic_ENVIRONMENT_VARIABLES___globals;
    cpy_r_r15 = CPyStatics[15]; /* 'EnvVarFactory' */
    cpy_r_r16 = CPyDict_GetItem(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("typed_envs/ENVIRONMENT_VARIABLES.py", "<module>", 14, CPyStatic_ENVIRONMENT_VARIABLES___globals);
        goto CPyL15;
    }
    PyObject *cpy_r_r17[1] = {cpy_r_r13};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = PyObject_Vectorcall(cpy_r_r16, cpy_r_r18, 1, 0);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("typed_envs/ENVIRONMENT_VARIABLES.py", "<module>", 14, CPyStatic_ENVIRONMENT_VARIABLES___globals);
        goto CPyL15;
    }
    CPyStatic_ENVIRONMENT_VARIABLES____factory = cpy_r_r19;
    CPy_INCREF(CPyStatic_ENVIRONMENT_VARIABLES____factory);
    cpy_r_r20 = CPyStatic_ENVIRONMENT_VARIABLES___globals;
    cpy_r_r21 = CPyStatics[55]; /* '_factory' */
    cpy_r_r22 = CPyDict_SetItem(cpy_r_r20, cpy_r_r21, cpy_r_r19);
    CPy_DECREF(cpy_r_r19);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("typed_envs/ENVIRONMENT_VARIABLES.py", "<module>", 14, CPyStatic_ENVIRONMENT_VARIABLES___globals);
        goto CPyL15;
    }
    cpy_r_r24 = CPyStatic_ENVIRONMENT_VARIABLES____factory;
    if (likely(cpy_r_r24 != NULL)) goto CPyL12;
    PyErr_SetString(PyExc_NameError, "value for final name \"_factory\" was not set");
    cpy_r_r25 = 0;
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("typed_envs/ENVIRONMENT_VARIABLES.py", "<module>", 20, CPyStatic_ENVIRONMENT_VARIABLES___globals);
        goto CPyL15;
    }
    CPy_Unreachable();
CPyL12: ;
    cpy_r_r26 = CPyStatics[56]; /* 'SHUTUP' */
    cpy_r_r27 = (PyObject *)&PyBool_Type;
    cpy_r_r28 = CPyStatics[4]; /* 'create_env' */
    cpy_r_r29 = 0 ? Py_True : Py_False;
    cpy_r_r30 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r31[5] = {cpy_r_r24, cpy_r_r26, cpy_r_r27, cpy_r_r29, cpy_r_r30};
    cpy_r_r32 = (PyObject **)&cpy_r_r31;
    cpy_r_r33 = CPyStatics[74]; /* ('verbose',) */
    cpy_r_r34 = PyObject_VectorcallMethod(cpy_r_r28, cpy_r_r32, 9223372036854775812ULL, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("typed_envs/ENVIRONMENT_VARIABLES.py", "<module>", 20, CPyStatic_ENVIRONMENT_VARIABLES___globals);
        goto CPyL15;
    }
    CPyStatic_ENVIRONMENT_VARIABLES___SHUTUP = cpy_r_r34;
    CPy_INCREF(CPyStatic_ENVIRONMENT_VARIABLES___SHUTUP);
    cpy_r_r35 = CPyStatic_ENVIRONMENT_VARIABLES___globals;
    cpy_r_r36 = CPyStatics[56]; /* 'SHUTUP' */
    cpy_r_r37 = CPyDict_SetItem(cpy_r_r35, cpy_r_r36, cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    cpy_r_r38 = cpy_r_r37 >= 0;
    if (unlikely(!cpy_r_r38)) {
        CPy_AddTraceback("typed_envs/ENVIRONMENT_VARIABLES.py", "<module>", 20, CPyStatic_ENVIRONMENT_VARIABLES___globals);
        goto CPyL15;
    }
    return 1;
CPyL15: ;
    cpy_r_r39 = 2;
    return cpy_r_r39;
}
static int registry_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_typed_envs___registry_internal, "__name__");
    CPyStatic_registry___globals = PyModule_GetDict(CPyModule_typed_envs___registry_internal);
    if (unlikely(CPyStatic_registry___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_registry_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_typed_envs___registry_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic_registry___ENVIRONMENT);
    CPyStatic_registry___ENVIRONMENT = NULL;
    CPy_XDECREF(CPyStatic_registry____ENVIRONMENT_VARIABLES_SET_BY_USER);
    CPyStatic_registry____ENVIRONMENT_VARIABLES_SET_BY_USER = NULL;
    CPy_XDECREF(CPyStatic_registry____ENVIRONMENT_VARIABLES_USING_DEFAULTS);
    CPyStatic_registry____ENVIRONMENT_VARIABLES_USING_DEFAULTS = NULL;
    return -1;
}
static PyMethodDef registrymodule_methods[] = {
    {"_register_new_env", (PyCFunction)CPyPy_registry____register_new_env, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef registrymodule = {
    PyModuleDef_HEAD_INIT,
    "typed_envs.registry",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    registrymodule_methods,
    NULL,
};

PyObject *CPyInit_typed_envs___registry(void)
{
    if (CPyModule_typed_envs___registry_internal) {
        Py_INCREF(CPyModule_typed_envs___registry_internal);
        return CPyModule_typed_envs___registry_internal;
    }
    CPyModule_typed_envs___registry_internal = PyModule_Create(&registrymodule);
    if (unlikely(CPyModule_typed_envs___registry_internal == NULL))
        goto fail;
    if (registry_exec(CPyModule_typed_envs___registry_internal) != 0)
        goto fail;
    return CPyModule_typed_envs___registry_internal;
    fail:
    return NULL;
}

char CPyDef_registry____register_new_env(PyObject *cpy_r_name, PyObject *cpy_r_instance) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    int32_t cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    int32_t cpy_r_r9;
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    int32_t cpy_r_r13;
    char cpy_r_r14;
    char cpy_r_r15;
    cpy_r_r0 = CPyStatic_registry___ENVIRONMENT;
    if (likely(cpy_r_r0 != NULL)) goto CPyL3;
    PyErr_SetString(PyExc_NameError, "value for final name \"ENVIRONMENT\" was not set");
    cpy_r_r1 = 0;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("typed_envs/registry.py", "_register_new_env", 13, CPyStatic_registry___globals);
        goto CPyL16;
    }
    CPy_Unreachable();
CPyL3: ;
    cpy_r_r2 = CPyDict_SetItem(cpy_r_r0, cpy_r_name, cpy_r_instance);
    cpy_r_r3 = cpy_r_r2 >= 0;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("typed_envs/registry.py", "_register_new_env", 13, CPyStatic_registry___globals);
        goto CPyL16;
    }
    cpy_r_r4 = CPyStatics[57]; /* '_using_default' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_instance, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("typed_envs/registry.py", "_register_new_env", 14, CPyStatic_registry___globals);
        goto CPyL16;
    }
    if (unlikely(!PyBool_Check(cpy_r_r5))) {
        CPy_TypeError("bool", cpy_r_r5); cpy_r_r6 = 2;
    } else
        cpy_r_r6 = cpy_r_r5 == Py_True;
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r6 == 2)) {
        CPy_AddTraceback("typed_envs/registry.py", "_register_new_env", 14, CPyStatic_registry___globals);
        goto CPyL16;
    }
    if (!cpy_r_r6) goto CPyL11;
    cpy_r_r7 = CPyStatic_registry____ENVIRONMENT_VARIABLES_USING_DEFAULTS;
    if (likely(cpy_r_r7 != NULL)) goto CPyL10;
    PyErr_SetString(PyExc_NameError, "value for final name \"_ENVIRONMENT_VARIABLES_USING_DEFAULTS\" was not set");
    cpy_r_r8 = 0;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("typed_envs/registry.py", "_register_new_env", 15, CPyStatic_registry___globals);
        goto CPyL16;
    }
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r9 = CPyDict_SetItem(cpy_r_r7, cpy_r_name, cpy_r_instance);
    cpy_r_r10 = cpy_r_r9 >= 0;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("typed_envs/registry.py", "_register_new_env", 15, CPyStatic_registry___globals);
        goto CPyL16;
    } else
        goto CPyL15;
CPyL11: ;
    cpy_r_r11 = CPyStatic_registry____ENVIRONMENT_VARIABLES_SET_BY_USER;
    if (likely(cpy_r_r11 != NULL)) goto CPyL14;
    PyErr_SetString(PyExc_NameError, "value for final name \"_ENVIRONMENT_VARIABLES_SET_BY_USER\" was not set");
    cpy_r_r12 = 0;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("typed_envs/registry.py", "_register_new_env", 17, CPyStatic_registry___globals);
        goto CPyL16;
    }
    CPy_Unreachable();
CPyL14: ;
    cpy_r_r13 = CPyDict_SetItem(cpy_r_r11, cpy_r_name, cpy_r_instance);
    cpy_r_r14 = cpy_r_r13 >= 0;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("typed_envs/registry.py", "_register_new_env", 17, CPyStatic_registry___globals);
        goto CPyL16;
    }
CPyL15: ;
    return 1;
CPyL16: ;
    cpy_r_r15 = 2;
    return cpy_r_r15;
}

PyObject *CPyPy_registry____register_new_env(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"name", "instance", 0};
    static CPyArg_Parser parser = {"OO:_register_new_env", kwlist, 0};
    PyObject *obj_name;
    PyObject *obj_instance;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_name, &obj_instance)) {
        return NULL;
    }
    PyObject *arg_name = obj_name;
    PyObject *arg_instance = obj_instance;
    char retval = CPyDef_registry____register_new_env(arg_name, arg_instance);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("typed_envs/registry.py", "_register_new_env", 12, CPyStatic_registry___globals);
    return NULL;
}

char CPyDef_registry_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    int32_t cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    int32_t cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    int32_t cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    CPyPtr cpy_r_r36;
    CPyPtr cpy_r_r37;
    CPyPtr cpy_r_r38;
    CPyPtr cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    int32_t cpy_r_r42;
    char cpy_r_r43;
    char cpy_r_r44;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[7]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("typed_envs/registry.py", "<module>", -1, CPyStatic_registry___globals);
        goto CPyL15;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[75]; /* ('Final',) */
    cpy_r_r6 = CPyStatics[12]; /* 'typing' */
    cpy_r_r7 = CPyStatic_registry___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("typed_envs/registry.py", "<module>", 1, CPyStatic_registry___globals);
        goto CPyL15;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[65]; /* ('EnvironmentVariable',) */
    cpy_r_r10 = CPyStatics[14]; /* 'typed_envs._env_var' */
    cpy_r_r11 = CPyStatic_registry___globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("typed_envs/registry.py", "<module>", 3, CPyStatic_registry___globals);
        goto CPyL15;
    }
    CPyModule_typed_envs____env_var = cpy_r_r12;
    CPy_INCREF(CPyModule_typed_envs____env_var);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[76]; /* ('EnvRegistry', 'VarName') */
    cpy_r_r14 = CPyStatics[23]; /* 'typed_envs.typing' */
    cpy_r_r15 = CPyStatic_registry___globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("typed_envs/registry.py", "<module>", 4, CPyStatic_registry___globals);
        goto CPyL15;
    }
    CPyModule_typed_envs___typing = cpy_r_r16;
    CPy_INCREF(CPyModule_typed_envs___typing);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = PyDict_New();
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("typed_envs/registry.py", "<module>", 7, CPyStatic_registry___globals);
        goto CPyL15;
    }
    CPyStatic_registry___ENVIRONMENT = cpy_r_r17;
    CPy_INCREF(CPyStatic_registry___ENVIRONMENT);
    cpy_r_r18 = CPyStatic_registry___globals;
    cpy_r_r19 = CPyStatics[18]; /* 'ENVIRONMENT' */
    cpy_r_r20 = CPyDict_SetItem(cpy_r_r18, cpy_r_r19, cpy_r_r17);
    CPy_DECREF(cpy_r_r17);
    cpy_r_r21 = cpy_r_r20 >= 0;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("typed_envs/registry.py", "<module>", 7, CPyStatic_registry___globals);
        goto CPyL15;
    }
    cpy_r_r22 = PyDict_New();
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("typed_envs/registry.py", "<module>", 8, CPyStatic_registry___globals);
        goto CPyL15;
    }
    CPyStatic_registry____ENVIRONMENT_VARIABLES_SET_BY_USER = cpy_r_r22;
    CPy_INCREF(CPyStatic_registry____ENVIRONMENT_VARIABLES_SET_BY_USER);
    cpy_r_r23 = CPyStatic_registry___globals;
    cpy_r_r24 = CPyStatics[19]; /* '_ENVIRONMENT_VARIABLES_SET_BY_USER' */
    cpy_r_r25 = CPyDict_SetItem(cpy_r_r23, cpy_r_r24, cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r26 = cpy_r_r25 >= 0;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("typed_envs/registry.py", "<module>", 8, CPyStatic_registry___globals);
        goto CPyL15;
    }
    cpy_r_r27 = PyDict_New();
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("typed_envs/registry.py", "<module>", 9, CPyStatic_registry___globals);
        goto CPyL15;
    }
    CPyStatic_registry____ENVIRONMENT_VARIABLES_USING_DEFAULTS = cpy_r_r27;
    CPy_INCREF(CPyStatic_registry____ENVIRONMENT_VARIABLES_USING_DEFAULTS);
    cpy_r_r28 = CPyStatic_registry___globals;
    cpy_r_r29 = CPyStatics[20]; /* '_ENVIRONMENT_VARIABLES_USING_DEFAULTS' */
    cpy_r_r30 = CPyDict_SetItem(cpy_r_r28, cpy_r_r29, cpy_r_r27);
    CPy_DECREF(cpy_r_r27);
    cpy_r_r31 = cpy_r_r30 >= 0;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("typed_envs/registry.py", "<module>", 9, CPyStatic_registry___globals);
        goto CPyL15;
    }
    cpy_r_r32 = CPyStatics[18]; /* 'ENVIRONMENT' */
    cpy_r_r33 = CPyStatics[19]; /* '_ENVIRONMENT_VARIABLES_SET_BY_USER' */
    cpy_r_r34 = CPyStatics[20]; /* '_ENVIRONMENT_VARIABLES_USING_DEFAULTS' */
    cpy_r_r35 = PyList_New(3);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("typed_envs/registry.py", "<module>", 20, CPyStatic_registry___globals);
        goto CPyL15;
    }
    cpy_r_r36 = (CPyPtr)&((PyListObject *)cpy_r_r35)->ob_item;
    cpy_r_r37 = *(CPyPtr *)cpy_r_r36;
    CPy_INCREF(cpy_r_r32);
    *(PyObject * *)cpy_r_r37 = cpy_r_r32;
    CPy_INCREF(cpy_r_r33);
    cpy_r_r38 = cpy_r_r37 + 8;
    *(PyObject * *)cpy_r_r38 = cpy_r_r33;
    CPy_INCREF(cpy_r_r34);
    cpy_r_r39 = cpy_r_r37 + 16;
    *(PyObject * *)cpy_r_r39 = cpy_r_r34;
    cpy_r_r40 = CPyStatic_registry___globals;
    cpy_r_r41 = CPyStatics[29]; /* '__all__' */
    cpy_r_r42 = CPyDict_SetItem(cpy_r_r40, cpy_r_r41, cpy_r_r35);
    CPy_DECREF_NO_IMM(cpy_r_r35);
    cpy_r_r43 = cpy_r_r42 >= 0;
    if (unlikely(!cpy_r_r43)) {
        CPy_AddTraceback("typed_envs/registry.py", "<module>", 20, CPyStatic_registry___globals);
        goto CPyL15;
    }
    return 1;
CPyL15: ;
    cpy_r_r44 = 2;
    return cpy_r_r44;
}
static int typing_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_typed_envs___typing_internal, "__name__");
    CPyStatic_typing___globals = PyModule_GetDict(CPyModule_typed_envs___typing_internal);
    if (unlikely(CPyStatic_typing___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_typing_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_typed_envs___typing_internal);
    Py_CLEAR(modname);
    return -1;
}
static PyMethodDef typingmodule_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef typingmodule = {
    PyModuleDef_HEAD_INIT,
    "typed_envs.typing",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    typingmodule_methods,
    NULL,
};

PyObject *CPyInit_typed_envs___typing(void)
{
    if (CPyModule_typed_envs___typing_internal) {
        Py_INCREF(CPyModule_typed_envs___typing_internal);
        return CPyModule_typed_envs___typing_internal;
    }
    CPyModule_typed_envs___typing_internal = PyModule_Create(&typingmodule);
    if (unlikely(CPyModule_typed_envs___typing_internal == NULL))
        goto fail;
    if (typing_exec(CPyModule_typed_envs___typing_internal) != 0)
        goto fail;
    return CPyModule_typed_envs___typing_internal;
    fail:
    return NULL;
}

char CPyDef_typing_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject **cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    int32_t cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject **cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    int32_t cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    tuple_T2OO cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject **cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    int32_t cpy_r_r52;
    char cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    CPyPtr cpy_r_r59;
    CPyPtr cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    tuple_T2OO cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    int32_t cpy_r_r69;
    char cpy_r_r70;
    char cpy_r_r71;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[7]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", -1, CPyStatic_typing___globals);
        goto CPyL23;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[77]; /* ('TYPE_CHECKING', 'Any', 'Callable', 'Dict', 'NewType') */
    cpy_r_r6 = CPyStatics[12]; /* 'typing' */
    cpy_r_r7 = CPyStatic_typing___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 1, CPyStatic_typing___globals);
        goto CPyL23;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[59]; /* 'VarName' */
    cpy_r_r10 = (PyObject *)&PyUnicode_Type;
    cpy_r_r11 = CPyStatic_typing___globals;
    cpy_r_r12 = CPyStatics[62]; /* 'NewType' */
    cpy_r_r13 = CPyDict_GetItem(cpy_r_r11, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 7, CPyStatic_typing___globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r14[2] = {cpy_r_r9, cpy_r_r10};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = PyObject_Vectorcall(cpy_r_r13, cpy_r_r15, 2, 0);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 7, CPyStatic_typing___globals);
        goto CPyL23;
    }
    cpy_r_r17 = CPyStatic_typing___globals;
    cpy_r_r18 = CPyStatics[59]; /* 'VarName' */
    cpy_r_r19 = CPyDict_SetItem(cpy_r_r17, cpy_r_r18, cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r20 = cpy_r_r19 >= 0;
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 7, CPyStatic_typing___globals);
        goto CPyL23;
    }
    cpy_r_r21 = CPyStatics[63]; /* 'VarValue' */
    cpy_r_r22 = (PyObject *)&PyUnicode_Type;
    cpy_r_r23 = CPyStatic_typing___globals;
    cpy_r_r24 = CPyStatics[62]; /* 'NewType' */
    cpy_r_r25 = CPyDict_GetItem(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 8, CPyStatic_typing___globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r26[2] = {cpy_r_r21, cpy_r_r22};
    cpy_r_r27 = (PyObject **)&cpy_r_r26;
    cpy_r_r28 = PyObject_Vectorcall(cpy_r_r25, cpy_r_r27, 2, 0);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 8, CPyStatic_typing___globals);
        goto CPyL23;
    }
    cpy_r_r29 = CPyStatic_typing___globals;
    cpy_r_r30 = CPyStatics[63]; /* 'VarValue' */
    cpy_r_r31 = CPyDict_SetItem(cpy_r_r29, cpy_r_r30, cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    cpy_r_r32 = cpy_r_r31 >= 0;
    if (unlikely(!cpy_r_r32)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 8, CPyStatic_typing___globals);
        goto CPyL23;
    }
    cpy_r_r33 = CPyStatics[58]; /* 'EnvRegistry' */
    cpy_r_r34 = CPyStatic_typing___globals;
    cpy_r_r35 = CPyStatics[61]; /* 'Dict' */
    cpy_r_r36 = CPyDict_GetItem(cpy_r_r34, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 10, CPyStatic_typing___globals);
        goto CPyL23;
    }
    cpy_r_r37 = CPyStatic_typing___globals;
    cpy_r_r38 = CPyStatics[59]; /* 'VarName' */
    cpy_r_r39 = CPyDict_GetItem(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 10, CPyStatic_typing___globals);
        goto CPyL24;
    }
    cpy_r_r40 = CPyStatics[13]; /* 'EnvironmentVariable' */
    CPy_INCREF(cpy_r_r40);
    cpy_r_r41.f0 = cpy_r_r39;
    cpy_r_r41.f1 = cpy_r_r40;
    cpy_r_r42 = PyTuple_New(2);
    if (unlikely(cpy_r_r42 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp9 = cpy_r_r41.f0;
    PyTuple_SET_ITEM(cpy_r_r42, 0, __tmp9);
    PyObject *__tmp10 = cpy_r_r41.f1;
    PyTuple_SET_ITEM(cpy_r_r42, 1, __tmp10);
    cpy_r_r43 = PyObject_GetItem(cpy_r_r36, cpy_r_r42);
    CPy_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 10, CPyStatic_typing___globals);
        goto CPyL23;
    }
    cpy_r_r44 = CPyStatic_typing___globals;
    cpy_r_r45 = CPyStatics[62]; /* 'NewType' */
    cpy_r_r46 = CPyDict_GetItem(cpy_r_r44, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 10, CPyStatic_typing___globals);
        goto CPyL25;
    }
    PyObject *cpy_r_r47[2] = {cpy_r_r33, cpy_r_r43};
    cpy_r_r48 = (PyObject **)&cpy_r_r47;
    cpy_r_r49 = PyObject_Vectorcall(cpy_r_r46, cpy_r_r48, 2, 0);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 10, CPyStatic_typing___globals);
        goto CPyL25;
    }
    CPy_DECREF(cpy_r_r43);
    cpy_r_r50 = CPyStatic_typing___globals;
    cpy_r_r51 = CPyStatics[58]; /* 'EnvRegistry' */
    cpy_r_r52 = CPyDict_SetItem(cpy_r_r50, cpy_r_r51, cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    cpy_r_r53 = cpy_r_r52 >= 0;
    if (unlikely(!cpy_r_r53)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 10, CPyStatic_typing___globals);
        goto CPyL23;
    }
    cpy_r_r54 = CPyStatic_typing___globals;
    cpy_r_r55 = CPyStatics[60]; /* 'Callable' */
    cpy_r_r56 = CPyDict_GetItem(cpy_r_r54, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 12, CPyStatic_typing___globals);
        goto CPyL23;
    }
    cpy_r_r57 = (PyObject *)&PyUnicode_Type;
    cpy_r_r58 = PyList_New(1);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 12, CPyStatic_typing___globals);
        goto CPyL26;
    }
    cpy_r_r59 = (CPyPtr)&((PyListObject *)cpy_r_r58)->ob_item;
    cpy_r_r60 = *(CPyPtr *)cpy_r_r59;
    CPy_INCREF(cpy_r_r57);
    *(PyObject * *)cpy_r_r60 = cpy_r_r57;
    cpy_r_r61 = CPyStatic_typing___globals;
    cpy_r_r62 = CPyStatics[8]; /* 'Any' */
    cpy_r_r63 = CPyDict_GetItem(cpy_r_r61, cpy_r_r62);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 12, CPyStatic_typing___globals);
        goto CPyL27;
    }
    cpy_r_r64.f0 = cpy_r_r58;
    cpy_r_r64.f1 = cpy_r_r63;
    cpy_r_r65 = PyTuple_New(2);
    if (unlikely(cpy_r_r65 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp11 = cpy_r_r64.f0;
    PyTuple_SET_ITEM(cpy_r_r65, 0, __tmp11);
    PyObject *__tmp12 = cpy_r_r64.f1;
    PyTuple_SET_ITEM(cpy_r_r65, 1, __tmp12);
    cpy_r_r66 = PyObject_GetItem(cpy_r_r56, cpy_r_r65);
    CPy_DECREF(cpy_r_r56);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 12, CPyStatic_typing___globals);
        goto CPyL23;
    }
    cpy_r_r67 = CPyStatic_typing___globals;
    cpy_r_r68 = CPyStatics[22]; /* 'StringConverter' */
    cpy_r_r69 = CPyDict_SetItem(cpy_r_r67, cpy_r_r68, cpy_r_r66);
    CPy_DECREF(cpy_r_r66);
    cpy_r_r70 = cpy_r_r69 >= 0;
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("typed_envs/typing.py", "<module>", 12, CPyStatic_typing___globals);
        goto CPyL23;
    }
    return 1;
CPyL23: ;
    cpy_r_r71 = 2;
    return cpy_r_r71;
CPyL24: ;
    CPy_DecRef(cpy_r_r36);
    goto CPyL23;
CPyL25: ;
    CPy_DecRef(cpy_r_r43);
    goto CPyL23;
CPyL26: ;
    CPy_DecRef(cpy_r_r56);
    goto CPyL23;
CPyL27: ;
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r58);
    goto CPyL23;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_typed_envs = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_typed_envs____env_var = Py_None;
    CPyModule_typed_envs___factory = Py_None;
    CPyModule_typed_envs___registry = Py_None;
    CPyModule_typed_envs___typing = Py_None;
    CPyModule_typed_envs____typed = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_functools = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_typed_envs____env_var = Py_None;
    CPyModule_typed_envs___ENVIRONMENT_VARIABLES = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_typed_envs___factory = Py_None;
    CPyModule_typed_envs___registry = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_typed_envs____env_var = Py_None;
    CPyModule_typed_envs___typing = Py_None;
    CPyModule_typed_envs___typing = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[78];
const char * const CPyLit_Str[] = {
    "\006\017default_factory\ncreate_env\020string_converter\averbose\bbuiltins\003Any",
    "\006\bOptional\004Type\aTypeVar\006typing\023EnvironmentVariable\023typed_envs._env_var",
    "\004\rEnvVarFactory\006logger\022typed_envs.factory\vENVIRONMENT",
    "\001\"_ENVIRONMENT_VARIABLES_SET_BY_USER",
    "\002%_ENVIRONMENT_VARIABLES_USING_DEFAULTS\023typed_envs.registry",
    "\002\017StringConverter\021typed_envs.typing",
    "\001\202ytyped_envs is used to create specialized `EnvironmentVariable` objects that behave exactly the same as any other instance of the `typ` used to create them.\n\ntyped_envs is used for:\n    - defining your envs in a readable, user friendly way\n    - enhancing type hints for the returned instances\n    - enhancing __repr__ of the returned instance with extra contextual information\n",
    "\001\vdescription",
    "\001\205M\nIn the example below, `some_var` can be used just like as any other `int` object.\n\n```\nimport typed_envs\nsome_var = typed_envs.create_env(\"SET_WITH_THIS_ENV\", int, 10)\n>>> isinstance(some_var, int)\nTrue\n>>> isinstance(some_var, EnvironmentVariable)\nTrue\n```\n\nThere are only 2 differences between `some_var` and `int(10)`:\n    - `some_var` will properly type check as an instance of both `int` and `EnvironmentVariable`\n    - `some_var.__repr__()` will include contextual information about the `EnvironmentVariable`.\n\n```\n>>> some_var\n<EnvironmentVariable[name=`SET_WITH_THIS_ENV`, type=int, default_value=10, current_value=10, using_default=True]>\n>>> str(some_var)\n\"10\"\n>>> some_var + 5\n15\n>>> 20 / some_var\n2\n```\n\n",
    "\a\021description_addon\001T\a__all__\024EnvironmentVariable[\b__name__\001]\b__args__",
    "\005\n__module__\f__qualname__\a__doc__\017__annotations__\016__parameters__",
    "\t\tTypeError\004args\abases: \atyped: \003map\tlru_cache\tfunctools\005Final\b__repr__",
    "\005\a__str__\n__origin__\032__TYPED_CLS_DICT_CONSTANTS\016build_subclass\amaxsize",
    "\006\rTYPE_CHECKING\tTYPEDENVS\b_factory\006SHUTUP\016_using_default\vEnvRegistry",
    "\005\aVarName\bCallable\004Dict\aNewType\bVarValue",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    14, 4, 8, 9, 10, 11, 1, 13, 3, 15, 16, 3, 3, 18, 19, 20, 1, 22, 1,
    44, 3, 46, 10, 11, 1, 52, 2, 53, 46, 1, 15, 1, 6, 1, 46, 2, 58, 59, 5,
    53, 8, 60, 61, 62
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_typed_envs_internal = NULL;
CPyModule *CPyModule_typed_envs;
PyObject *CPyStatic_typed_envs___globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_typed_envs____env_var;
CPyModule *CPyModule_typed_envs___factory;
CPyModule *CPyModule_typed_envs___registry_internal = NULL;
CPyModule *CPyModule_typed_envs___registry;
CPyModule *CPyModule_typed_envs___typing_internal = NULL;
CPyModule *CPyModule_typed_envs___typing;
CPyModule *CPyModule_typed_envs____typed_internal = NULL;
CPyModule *CPyModule_typed_envs____typed;
PyObject *CPyStatic__typed___globals;
CPyModule *CPyModule_functools;
CPyModule *CPyModule_typed_envs___ENVIRONMENT_VARIABLES_internal = NULL;
CPyModule *CPyModule_typed_envs___ENVIRONMENT_VARIABLES;
PyObject *CPyStatic_ENVIRONMENT_VARIABLES___globals;
PyObject *CPyStatic_registry___globals;
PyObject *CPyStatic_typing___globals;
PyObject *CPyDef_typed_envs___create_env(PyObject *cpy_r_name, PyObject *cpy_r_typ, PyObject *cpy_r_default, PyObject *cpy_r_init_args, PyObject *cpy_r_string_converter, char cpy_r_verbose, PyObject *cpy_r_init_kwargs);
PyObject *CPyPy_typed_envs___create_env(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_typed_envs_____top_level__(void);
PyObject *CPyStatic__typed_____TYPED_CLS_DICT_CONSTANTS = NULL;
PyObject *CPyDef__typed___build_subclass(PyObject *cpy_r_type_arg);
PyObject *CPyPy__typed___build_subclass(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__typed_____top_level__(void);
PyObject *CPyStatic_ENVIRONMENT_VARIABLES____factory = NULL;
PyObject *CPyStatic_ENVIRONMENT_VARIABLES___SHUTUP = NULL;
char CPyDef_ENVIRONMENT_VARIABLES_____top_level__(void);
PyObject *CPyStatic_registry___ENVIRONMENT = NULL;
PyObject *CPyStatic_registry____ENVIRONMENT_VARIABLES_SET_BY_USER = NULL;
PyObject *CPyStatic_registry____ENVIRONMENT_VARIABLES_USING_DEFAULTS = NULL;
char CPyDef_registry____register_new_env(PyObject *cpy_r_name, PyObject *cpy_r_instance);
PyObject *CPyPy_registry____register_new_env(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_registry_____top_level__(void);
char CPyDef_typing_____top_level__(void);

static struct export_table_303c4825a0ce575d88a6 exports = {
    &CPyDef_typed_envs___create_env,
    &CPyDef_typed_envs_____top_level__,
    &CPyStatic__typed_____TYPED_CLS_DICT_CONSTANTS,
    &CPyDef__typed___build_subclass,
    &CPyDef__typed_____top_level__,
    &CPyStatic_ENVIRONMENT_VARIABLES____factory,
    &CPyStatic_ENVIRONMENT_VARIABLES___SHUTUP,
    &CPyDef_ENVIRONMENT_VARIABLES_____top_level__,
    &CPyStatic_registry___ENVIRONMENT,
    &CPyStatic_registry____ENVIRONMENT_VARIABLES_SET_BY_USER,
    &CPyStatic_registry____ENVIRONMENT_VARIABLES_USING_DEFAULTS,
    &CPyDef_registry____register_new_env,
    &CPyDef_registry_____top_level__,
    &CPyDef_typing_____top_level__,
};

PyMODINIT_FUNC PyInit_303c4825a0ce575d88a6__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "303c4825a0ce575d88a6__mypyc", NULL, -1, NULL, NULL };
    int res;
    PyObject *capsule;
    PyObject *tmp;
    static PyObject *module;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&def);
    if (!module) {
        goto fail;
    }
    
    capsule = PyCapsule_New(&exports, "303c4825a0ce575d88a6__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_typed_envs(void);
    capsule = PyCapsule_New((void *)CPyInit_typed_envs, "303c4825a0ce575d88a6__mypyc.init_typed_envs", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_typed_envs", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_typed_envs____typed(void);
    capsule = PyCapsule_New((void *)CPyInit_typed_envs____typed, "303c4825a0ce575d88a6__mypyc.init_typed_envs____typed", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_typed_envs____typed", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_typed_envs___ENVIRONMENT_VARIABLES(void);
    capsule = PyCapsule_New((void *)CPyInit_typed_envs___ENVIRONMENT_VARIABLES, "303c4825a0ce575d88a6__mypyc.init_typed_envs___ENVIRONMENT_VARIABLES", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_typed_envs___ENVIRONMENT_VARIABLES", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_typed_envs___registry(void);
    capsule = PyCapsule_New((void *)CPyInit_typed_envs___registry, "303c4825a0ce575d88a6__mypyc.init_typed_envs___registry", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_typed_envs___registry", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_typed_envs___typing(void);
    capsule = PyCapsule_New((void *)CPyInit_typed_envs___typing, "303c4825a0ce575d88a6__mypyc.init_typed_envs___typing", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_typed_envs___typing", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
