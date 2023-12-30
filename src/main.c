
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "DataStructures/Array.h"

#include "Functions/LLFunction.h"
#include "Functions/LLType.h"
#include "Functions/LLTypeCase.h"

#include "Utils/Utils.h"

int main() {
    
    LLType *t = ll_type_init(ll_type_flt, NULL);
    
    printf("Description: %s\n", ll_type_description(t));
    
    return 0;
    
}
