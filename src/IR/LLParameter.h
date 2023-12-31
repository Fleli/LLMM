
#pragma once

#include "LLType.h"

/* An `LLParameter` represents a function parameter, including `name` and `type`. */
typedef struct {
    
    char *name;
    LLType *type;
    
} LLParameter;

/* 
Initialize a new `LLParameter` instance. 
Assumes that this new parameter will get ownership of `name` and `type`.
Will not make copies of these.
*/
LLParameter *ll_parameter_init(char *name, LLType *type);

/* Destroy an LLParameter instance. */
void ll_parameter_destroy(LLParameter *parameter);

/* Get a string `type name` describing the parameter. */
char *ll_parameter_description(LLParameter *parameter);
