
#pragma once

#include "../DataStructures/Array.h"

/* A label is an ordered list of statements. Together, several labels make up a function. */
typedef struct {
    
    char *name;
    Array *statements;
    
} LLLabel;

/* Initialize a new `LLLabel` instance. The new label takes ownership of the `nane` string.*/
LLLabel *ll_label_init(char *name);
