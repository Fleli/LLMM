
#include <stdlib.h>
#include <stdio.h>

#include "../meta.h"
#include "../DataStructures/Array.h"

#include "../IR/LLLabel.h"
#include "../IR/LLStmt.h"

#include "../Utils/Utils.h"

LLLabel *ll_label_init(char *name) {
    
    LLLabel *label = malloc( sizeof(LLLabel) );
    
    #ifdef PRINTOBJECTS
    printf("Label @ %p\n", label);
    #endif
    
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

char *ll_label_description(LLLabel *label) {
    
    MutableString *mstr = mutable_string_init("\t", do_not_take_ownership);
    
    mutable_string_concatenate(mstr, label->name, do_not_take_ownership);
    mutable_string_concatenate(mstr, ":", do_not_take_ownership);
    
    int count = array_count(label->statements);
    
    for (int i = 0; i < count; i++) {
        
        LLStmt *elem = array_get(label->statements, i);
        char *elemDescription = ll_stmt_description(elem);
        
        mutable_string_concatenate(mstr, "\n\t\t", do_not_take_ownership);
        mutable_string_concatenate(mstr, elemDescription, take_ownership);
        
    }
    
    mutable_string_concatenate(mstr, "\n", do_not_take_ownership);
    
    return mutable_string_destroy_extract_buffer(mstr);
    
}
