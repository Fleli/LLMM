
#include <stdlib.h>

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
