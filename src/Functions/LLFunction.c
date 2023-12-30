
#include <stdlib.h> 

#include "../DataStructures/Array.h"

#include "../IR/LLFunction.h"
#include "../IR/LLParameter.h"

LLFunction *ll_function_init(char* name) {
    
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
