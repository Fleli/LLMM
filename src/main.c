
#include "meta.h"

#include "IR/LLFunction.h"
#include "IR/LLParameter.h"
#include "IR/LLType.h"
#include "IR/LLFunctionType.h"

#include "Utils/Utils.h"

void test1() {
    
    char *funcName = heap_string("do_something");
    LLFunction *func = ll_function_init(funcName);
    
    char *p1Name = heap_string("x");
    LLType *p1Type = ll_type_init(ll_type_i16, NULL);
    LLParameter *p1 = ll_parameter_init(p1Name, p1Type);
    ll_function_add_parameter(func, p1);
    
    char *p2Name = heap_string("y");
    LLType *in = ll_type_init(ll_type_i16, NULL);
    LLType *out = ll_type_init(ll_type_flt, NULL);
    LLFunctionType *llft = ll_function_type_init(in, out);
    LLType *p2Type = ll_type_init(ll_type_function, llft);
    LLParameter *p2 = ll_parameter_init(p2Name, p2Type);
    ll_function_add_parameter(func, p2);
    
    char *desc = ll_function_description(func);
    
    printf("%s\n", desc);
    
    free(desc);
    ll_function_destroy(func);
    
}

int main() {
    
    test1();
    
    return 0;
    
}

