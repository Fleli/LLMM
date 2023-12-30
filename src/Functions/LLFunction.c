
#include <stdlib.h>

#include "LLFunction.h"
#include "../DataStructures/Array.h"

LLFunction *ll_function_init(char* name) {
    
    LLFunction *func = malloc( sizeof(LLFunction) );
    
    func->name = name;
    func->labels = array_init();
    func->parameters = array_init();
    
    return func;
    
}
