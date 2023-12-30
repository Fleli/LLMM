
#include <stdlib.h>

#include "LLLabel.h"
#include "../DataStructures/Array.h"

LLLabel *ll_label_init(char *name) {
    
    LLLabel *label = malloc( sizeof(LLLabel) );
    
    label->name = name;
    label->statements = array_init();
    
    return label;
    
}
