
#include <stdlib.h>
#include <stdio.h>

#include "../DataStructures/Array.h"

#include "../IR/LLType.h"
#include "../IR/LLFunctionType.h"

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
    
    // If the type case is a function, the associated value is a function type (LLFunctionType).
    if (type->typeCase == ll_type_function) {
        ll_function_type_destroy(type->associated_value);
    }
    
    // If the type case is a struct, we have to destroy an entire array of underlying types.
    if (type->typeCase == ll_type_struct) {
        Array *underlying_types = type->associated_value;
        array_destroy_with_ownership(underlying_types, ll_type_destroy);
    }
    
    // Then, we deallocate this LLType instance.
    free(type);
    
}

char *ll_type_description(LLType *t) {
    
    switch (t->typeCase) {
        case ll_type_i1:
            return heap_string("i1");
        case ll_type_i8:
            return heap_string("i8");
        case ll_type_i16:
            return heap_string("i16");
        case ll_type_i32:
            return heap_string("i32");
        case ll_type_flt:
            return heap_string("flt");
        case ll_type_ptr:
        
            // Make a mutable description from the underlying type's description.
            char *u_description = ll_type_description( (LLType *) t->associated_value );
            MutableString *mstring = mutable_string_init(u_description, take_ownership);
            
            // Append '*' to it to show that this is a pointer to that type, and return.
            mutable_string_concatenate(mstring, "*", do_not_take_ownership);
            return mutable_string_destroy_extract_buffer(mstring);
            
        case ll_type_function:
        
            return ll_function_type_description( (LLFunctionType *) t->associated_value );
            
        case ll_type_struct:
            
            
            
        default:
            printf("Unrecognized LLType case %d.\n", t->typeCase);
            exit(1);
        
    }
    
}
