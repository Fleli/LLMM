
#include <stdlib.h>

#include "../meta.h"

#include "../IR/LLType.h"

#include "../IR/LLParameter.h"

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

char *ll_parameter_description(LLParameter *parameter) {
    
    // Build a mutable string that takes ownership of the type description.
    char *typeDesc = ll_type_description(parameter->type);
    MutableString *description = mutable_string_init(typeDesc, take_ownership);
    
    // Append a space to it.
    mutable_string_concatenate(description, " ", do_not_take_ownership);
    
    // Append the name (but don't take ownership, since the name belongs to the instance itself).
    mutable_string_concatenate(description, parameter->name, do_not_take_ownership);
    
    // Extract and return the buffer (the final string). Destroy the `MutableString` instance.
    return mutable_string_destroy_extract_buffer(description);
    
}
