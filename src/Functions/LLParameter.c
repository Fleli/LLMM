
#include <stdlib.h>

#include "LLParameter.h"
#include "LLType.h"

LLParameter *ll_parameter_init(char *name, LLType *type) {
    
    LLParameter *llp = malloc( sizeof(LLParameter) );
    
    llp->name = name;
    llp->type = type;
    
    return llp;
    
}
