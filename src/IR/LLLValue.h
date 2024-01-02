
#pragma once

#include "LLLValueCase.h"

/* 

The `LLLValue` struct (for LValues) is organized like a Swift enum.
It has two components:
- The `valueCase`, which describes which kind of LValue this is.
- The `assocated_value`, which points to some data providing more information.

In the case of an `ll_lvalue_variable`, the associated value is a `char *` containing the name of
that variable.

In the case of an `ll_lvalue_pointer`, the associated value is a `char *` containing the name of the
variable that is being dereferenced.

*/
typedef struct {
    
    /* The active case for this LValue, either `ll_lvalue_variable` or `ll_lvalue_pointer` */
    LLLValueCase valueCase;
    
    /* The associated value (if any). */
    void *associated_value;
    
} LLLValue;

/* Initialize an instance of `LLLValue`. Takes ownership of the associated value. */
LLLValue *ll_lvalue_init(LLLValueCase valueCase, void *associated_value);

/* Destroy an `LLLValue` instance and free its memory. */
void ll_lvalue_destroy(LLLValue *lvalue);
