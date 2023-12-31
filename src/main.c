
#include "meta.h"

#include "IR/LLFunction.h"
#include "IR/LLParameter.h"
#include "IR/LLType.h"

#include "Utils/Utils.h"

int main() {
    
    /*
    char *funcName = heap_string("didMoveToView");
    LLFunction *func = ll_function_init(funcName);
    
    char *paramName = heap_string("%%1");
    LLType *type = ll_type_init(ll_type_i16, NULL);
    LLParameter *param = ll_parameter_init(paramName, type);
    
    ll_function_add_parameter(func, param);
    
    ll_function_destroy(func);
    */
    
    MutableString *mut_str = mutable_string_init("abc", bool_false);
    
    char *p = heap_string("def");
    char *q = heap_string("ghi");
    
    mutable_string_concatenate(mut_str, p, bool_true);
    mutable_string_concatenate(mut_str, q, bool_true);
    
    printf("%s\n", mut_str->buffer);
    
    mutable_string_destroy(mut_str);
    
    return 0;
    
}
