
#include <stdlib.h> 

#include "../DataStructures/Array.h"

#include "../IR/LLFunction.h"
#include "../IR/LLParameter.h"

LLFunction *ll_function_init(char *name) {
    
    LLFunction *func = malloc( sizeof(LLFunction) );
    
    func->name = name;
    func->labels = array_init();
    func->parameters = array_init();
    
    return func;
    
}

void ll_function_add_parameter(LLFunction *func, LLParameter *param) {
    array_append(func->parameters, param);
}

void ll_function_add_label(LLFunction *func, LLLabel *label) {
    array_append(func->labels, label);
}

void ll_function_destroy(LLFunction *func) {
    
    // Free the string holding the function's name.
    free(func->name);
    
    // Free parameters and labels
    array_destroy_with_ownership(func->parameters, (destructor) ll_parameter_destroy);
    array_destroy_with_ownership(func->labels, (destructor) ll_label_destroy);
    
    // Free the function itself
    free(func);
    
}

char *ll_function_description(LLFunction *func) {
    
    MutableString *description = mutable_string_init("[func] ", do_not_take_ownership);
    mutable_string_concatenate(description, func->name, do_not_take_ownership);
    mutable_string_concatenate(description, "(", do_not_take_ownership);
    
    int paramCount = array_count(func->parameters);
    
    for (int i = 0 ; i < paramCount - 1 ; i++) {
        
        // Find the relevant parameter instance.
        LLParameter *param = array_get(func->parameters, i);
        
        // Append the parameter's description, plus ", ", to the full description.
        char *paramDesc = ll_parameter_description(param);
        mutable_string_concatenate(description, paramDesc, take_ownership);
        mutable_string_concatenate(description, ", ", do_not_take_ownership);
        
    }
    
    if (paramCount > 0) {
        
        // Find the last parameter instance.
        LLParameter *param = array_get(func->parameters, paramCount - 1);
        
        // Append the parameter's description to the full description.
        char *paramDesc = ll_parameter_description(param);
        mutable_string_concatenate(description, paramDesc, take_ownership);
        
    }
    
    // End the parameter list.
    mutable_string_concatenate(description, ")", do_not_take_ownership);
    
    // TODO: Include label descriptions in the function description.
    
    // Destroy the mutable string, but extract and return the character buffer.
    return mutable_string_destroy_extract_buffer(description);
    
}
