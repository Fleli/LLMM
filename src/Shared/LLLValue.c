
#include <stdlib.h>
#include <stdio.h>

#include "../Utils/Utils.h"

#include "../IR/LLLValue.h"
#include "../IR/LLLValueCase.h"

LLLValue *ll_lvalue_init(LLLValueCase valueCase, void *associated_value) {
    
    LLLValue *lvalue = malloc( sizeof(LLLValue) );
    
    lvalue->valueCase = valueCase;
    lvalue->associated_value = associated_value;
    
    return lvalue;
    
}

void ll_lvalue_destroy(LLLValue *lvalue) {
    
    // TODO: Update if more cases are added.
    // In both cases, the associated value is a `char *`, so we just free it.
    free(lvalue->associated_value);
    
    // Free the instance itself.
    free(lvalue);
    
}

char *ll_lvalue_description(LLLValue *lvalue) {
    
    if (lvalue->valueCase == ll_lvalue_variable) {
        return heap_string(lvalue->associated_value);
    } else if (lvalue->valueCase == ll_lvalue_pointer) {
        MutableString *mstr = mutable_string_init("*", do_not_take_ownership);
        mutable_string_concatenate(mstr, lvalue->associated_value, do_not_take_ownership);
        return mutable_string_destroy_extract_buffer(mstr);
    } else {
        printf("Unexpected LValue case: %d\n.", lvalue->valueCase);
        exit(1);
    }
    
}
