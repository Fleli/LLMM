
#include "IR/LLFunction.h"
#include "IR/LLParameter.h"
#include "IR/LLType.h"

#include "Utils/Utils.h"

int main() {
    
    char *funcName = heap_string("didMoveToView");
    LLFunction *func = ll_function_init(funcName);
    
    char *paramName = heap_string("%%1");
    LLType *type = ll_type_init(ll_type_i16, NULL);
    LLParameter *param = ll_parameter_init(paramName, type);
    
    ll_function_add_parameter(func, param);
    
    ll_function_destroy(func);
    
    return 0;
    
}
