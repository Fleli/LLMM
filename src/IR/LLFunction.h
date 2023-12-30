
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

/* Initialize a new LLFunction object. */
LLFunction *ll_function_init(char* name);

/* Add a new parameter to a function. */
void ll_function_add_parameter(LLFunction *func, LLParameter *param);

/* Add a new label to a function. */
void ll_function_add_label(LLFunction *func, LLLabel *label);