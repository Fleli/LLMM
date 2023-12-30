
#include <stdlib.h>

#include "LLParameter.h"
#include "LLType.h"

LLParameter *ll_parameter_init(char *name, LLType *type) {
    
    LLParameter *llp = malloc( sizeof(LLParameter) );
    
    llp->name = name;
    llp->type = type;
    
    return llp;
    
}

void ll_parameter_destroy(LLParameter *parameter) {
    
    // Free the name string and the type.
    free(parameter->name);
    ll_type_destroy(parameter->type);
    
    // Then, free the parameter instance itself.
    free(parameter);
    
}
