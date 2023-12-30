
#include <stdlib.h>

#include "../DataStructures/Array.h"

#include "LLLabel.h"

#include "../Statements/LLStmt.h"

LLLabel *ll_label_init(char *name) {
    
    LLLabel *label = malloc( sizeof(LLLabel) );
    
    label->name = name;
    label->statements = array_init();
    
    return label;
    
}

void ll_label_add_statement(LLLabel *label, LLStmt *stmt) {
    array_append(label->statements, stmt);
}
