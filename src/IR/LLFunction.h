
#pragma once

#include <stdlib.h>

#include "../DataStructures/Array.h"

#include "LLParameter.h"
#include "LLLabel.h"

/* An LLFunction represents a function in LLMM. */
typedef struct {
    
    char *name;
    Array *labels;
    Array *parameters;
    
} LLFunction;

/* Initialize a new LLFunction object. Takes ownership of the `name` variable, so it must be heap-allocated. */
LLFunction *ll_function_init(char* name);

/* Add a new parameter to a function. Take ownership of the parameter. */
void ll_function_add_parameter(LLFunction *func, LLParameter *param);

/* Add a new label to a function. Take ownership of the label. */
void ll_function_add_label(LLFunction *func, LLLabel *label);

/* Destroy an LLFunction. */
void ll_function_destroy(LLFunction *func);

/* 
Return a string describing the function.
This includes its name & parameters, and all labels (which contains all the statements of the body).
 */
char *ll_function_description(LLFunction *func);
