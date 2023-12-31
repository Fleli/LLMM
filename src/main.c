
#include "meta.h"

#include "IR/LLFunction.h"
#include "IR/LLParameter.h"
#include "IR/LLType.h"

#include "Utils/Utils.h"

int main() {
    
    char *funcName = heap_string("test_function");
    LLFunction *func = ll_function_init(funcName);
    
    char *desc = ll_function_description(func);
    
    printf("%s\n", desc);
    
    ll_function_destroy(func);
    free(desc);
    
    return 0;
    
}
