
#include <stdlib.h>

#include "LLFunction.h"
#include "LLParameter.h"

#include "../DataStructures/Array.h"

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
