
#pragma once

#include "LLType.h"

typedef struct {
    
    LLType *input;
    LLType *output;
    
} LLFunctionType;

/* Initialize an `LLFunctionType` by taking ownership of in- and output types. */
LLFunctionType *ll_function_type_init(LLType *input, LLType *output);

/* Destroy an `LLFunctionType` instance and free its memory. */
void ll_function_type_destroy(LLFunctionType *ftype);

/* Get a description of the function type. */
char *ll_function_type_description(LLFunctionType *ftype);
