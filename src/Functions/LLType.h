
#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "LLTypeCase.h"
#include "../DataStructures/Array.h"
#include "../Utils/Utils.h"

/* 
An `LLType` is similar to a Swift enum. Its typeCase represents either a basic type, a pointer, or a struct.
The latter two also have associated values:
- pointers have an underlying `LLType`
- structs have arrays of underlying `LLType`s.
*/
typedef struct {
    
    LLTypeCase typeCase;
    void *associated_value;
    
} LLType;

/* 
Initialize a new LLType instance.
Assumes ownership of `associated` is given to this new instance. 
Won't make a copy of it.
 */
LLType *ll_type_init(LLTypeCase typeCase, void *associated);

/*
Returns a string describing the type.
The string is allocated on the heap.
*/
char *ll_type_description(LLType *t) {
    
    switch (t->typeCase) {
        case ll_type_i1:
            return heap_string("A 1-bit integer (boolean value).");
        case ll_type_i8:
            return heap_string("An 8-bit integer.");
        case ll_type_i16:
            return heap_string("A 16-bit integer.");
        case ll_type_i32:
            return heap_string("A 32-bit integer.");
        case ll_type_flt:
            return heap_string("A 16-bit floating point type.");
        default:
            printf("Unrecognized LLType case %d.\n", t->typeCase);
            exit(1);
            
    }
    
}
