
#pragma once

#include "LLRValueCase.h"

/* 
An `LLRValue` is organized similarly to Swift enums with associated values.
`LLRValue`s represent RValues.
They can be literals or variables.
*/
typedef struct {
    
    /* The RValue case. */
    LLRValueCase rvalueCase;
    
    /* The RValue instance's associated value. Its type varies with the case. */
    void *associated_value;
    
} LLRValue;

/* Initialize an `LLRValue` with an integer literal. Takes ownership of the literal allocation. */
LLRValue *ll_rvalue_init_literal(int *literal);

/* Initialize an `LLRValue` with a variable value. Takes ownership of the variable allocation. */
LLRValue *ll_rvalue_init_variable(char *variable);

/* Destroy an `LLRValue` instance. */
void ll_rvalue_destroy(LLRValue *rvalue);

/* Build a description of an RValue. */
char *ll_rvalue_description(LLRValue *rvalue);
