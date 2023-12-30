
#pragma once

#include <stdlib.h>

#include "../DataStructures/Array.h"

/* An LLFunction represents a function in LLMM. */
typedef struct {
    
    char *name;
    Array *labels;
    Array *parameters;
    
} LLFunction;

/* Initialize a new LLFunction object. */
LLFunction *llFunction_init(char* name);
