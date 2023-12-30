
#include <stdlib.h>
#include <stdio.h>

#include "../DataStructures/Array.h"

#include "../IR/LLType.h"

LLType *ll_type_init(LLTypeCase typeCase, void *associated) {
    
    LLType *t = malloc( sizeof(LLType) );
    
    t->typeCase = typeCase;
    t->associated_value = associated;
    
    return t;
    
}

void ll_type_destroy(LLType *type) {
    
    // If the type case is a pointer, the associated value is another LLType.
    if (type->typeCase == ll_type_ptr) {
        ll_type_destroy(type->associated_value);
    }
    
    // If the type case is a struct, we have to destroy an entire array of underlying types.
    if (type->typeCase == ll_type_struct) {
        
        Array *underlying_types = type->associated_value;
        int count = array_count(underlying_types);
        
        for (int i = 0; i < count; i++) {
            LLType *element = array_get(underlying_types, i);
            ll_type_destroy(element);
        }
        
        array_destroy(underlying_types);
        
    }
    
    // Then, we deallocate this LLType instance.
    free(type);
    
}

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
