
#include <stdlib.h>
#include <stdio.h>

#include "../meta.h"

#include "LLType.h"
#include "../DataStructures/Array.h"

LLType *ll_type_init(LLTypeCase typeCase, void *associated) {
    
    LLType *t = malloc( sizeof(LLType) );
    
    t->typeCase = typeCase;
    t->associated_value = associated;
    
    return t;
    
}
