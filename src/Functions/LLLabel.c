
#include <stdlib.h>

#include "../DataStructures/Array.h"

#include "../IR/LLLabel.h"

#include "../IR/LLStmt.h"

LLLabel *ll_label_init(char *name) {
    
    LLLabel *label = malloc( sizeof(LLLabel) );
    
    label->name = name;
    label->statements = array_init();
    
    return label;
    
}

void ll_label_add_statement(LLLabel *label, LLStmt *stmt) {
    array_append(label->statements, stmt);
}

void ll_label_destroy(LLLabel *label) {
    
    // Free the label's name string.
    free(label->name);
    
    // Free the label's array of statements.
    array_destroy_with_ownership(label->statements, (Destructor) ll_stmt_destroy);
    
    // Free the label itself.
    free(label);
    
}