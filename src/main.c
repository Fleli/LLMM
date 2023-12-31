
#include "meta.h"

#include "IR/LLFunction.h"
#include "IR/LLParameter.h"
#include "IR/LLType.h"

#include "Utils/Utils.h"

int main() {
    
    int types[] = { ll_type_i32, ll_type_i16, ll_type_i8 };
    char *names[] = { "x", "y", "z" };
    
    LLFunction *func = ll_function_init( heap_string("sum") );
    
    for (int i = 0; i < 3; i++) {
        LLParameter *param = ll_parameter_init( heap_string(names[i]) , ll_type_init(types[i], NULL) );
        ll_function_add_parameter(func, param);
    }
    
    char *desc = ll_function_description(func);
    
    printf("%s\n", desc);
    
    ll_function_destroy(func);
    free(desc);
    
    return 0;
    
}
