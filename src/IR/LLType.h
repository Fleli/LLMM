
#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "../DataStructures/Array.h"

#include "../Utils/Utils.h"

#include "LLTypeCase.h"

/* 
An `LLType` is similar to a Swift enum. Its typeCase represents either a basic type, a pointer, a function, or a struct.
The latter three also have associated values:
- pointers have an underlying `LLType`
- functions have an underlying `LLFunctionType`.
- structs have arrays of underlying `LLType`s.
*/
typedef struct {
    
    LLTypeCase typeCase;
    void *associated_value;
    
} LLType;

/* 
Initialize a new LLType instance.
Takes ownership of the `associated` value passed as argument.
 */
LLType *ll_type_init(LLTypeCase typeCase, void *associated);

/* Destroy an `LLType` instance and its associated value. */
void ll_type_destroy(LLType *type);

/*
Returns a string describing the type.
The string is allocated on the heap.
*/
char *ll_type_description(LLType *t);
