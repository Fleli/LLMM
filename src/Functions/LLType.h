
#pragma once

#include "LLTypeCase.h"
#include "../DataStructures/Array.h"

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

LLType *ll_type_init(LLTypeCase typeCase, void *associated);
