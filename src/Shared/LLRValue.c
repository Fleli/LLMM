
#include <stdlib.h>

#include "../IR/LLRValue.h"
#include "../IR/LLRValueCase.h"

LLRValue *ll_rvalue_init_literal(int *literal) {
    
    LLRValue *rvalue = malloc( sizeof(LLRValue) );
    
    rvalue->rvalueCase = ll_rvalue_int_literal;
    rvalue->associated_value = literal;
    
    return rvalue;
    
}

LLRValue *ll_rvalue_init_variable(char *variable) {
    
    LLRValue *rvalue = malloc( sizeof(LLRValue) );
    
    rvalue->rvalueCase = ll_rvalue_variable;
    rvalue->associated_value = variable;
    
    return rvalue;
    
}

void ll_rvalue_destroy(LLRValue *rvalue) {
    
    // Free the associated value.
    free(rvalue->associated_value);
    
    // Free the instance itself.
    free(rvalue);
    
}
