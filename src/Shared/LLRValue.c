
#include <stdlib.h>
#include <stdio.h>

#include "../Utils/Utils.h"

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

char *ll_rvalue_description(LLRValue *rvalue) {
    
    if (rvalue->rvalueCase == ll_rvalue_int_literal) {
        
        // 
        char *description = malloc( 20 * sizeof(char) );
        
        int literal = *( (int *) (rvalue->associated_value));
        
        sprintf(description, "%d", literal);
        
        return description;
        
    } else if (rvalue->rvalueCase == ll_rvalue_variable) {
        
        // Simply cast the associated value (variable) as a string and copy it (due to ownership rules).
        return heap_string(rvalue->associated_value);
        
    } else {
        
        printf("Unexpected rvalue case %d\n", rvalue->rvalueCase);
        exit(1);
        
    }
    
}
