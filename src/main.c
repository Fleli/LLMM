
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "DataStructures/Array.h"

#include "IR/LLFunction.h"
#include "IR/LLType.h"
#include "IR/LLTypeCase.h"

#include "Utils/Utils.h"

int main() {
    
    Array *a = array_init();
    
    int *t1 = malloc(sizeof(int));
    *t1 = 10;
    
    int *t2 = malloc(sizeof(int));
    *t2 = 20;
    
    array_append(a, t1);
    array_append(a, t2);
    
    array_destroy_with_ownership(a, free);
    
    return 0;
    
}
