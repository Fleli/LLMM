
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "DataStructures/Array.h"
#include "Functions/LLFunction.h"
#include "Utils/Utils.h"

int main() {
    
    char *name = heap_string("function_name");
    
    LLFunction *func = llFunction_init(name);
    
    printf("%s\n", func->name);
    
    return 0;
    
}
