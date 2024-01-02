
#include <stdlib.h>
#include <stdio.h>

#include "../meta.h"
#include "../Utils/Utils.h"

#include "../IR/LLStmt.h"
#include "../IR/LLType.h"
#include "../IR/LLLValue.h"
#include "../IR/LLStmtLoad.h"

LLStmt *ll_stmt_init_load(char *name, LLType *type, LLLValue *location) {
    
    LLStmt *stmt = malloc( sizeof(LLStmt) );
    
    #ifdef PRINTOBJECTS
    printf("LLStmt (load) @ %p\n", stmt);
    #endif
    
    stmt->mnemonic = heap_string("load");
    
    LLStmtLoad *load = malloc( sizeof(LLStmtLoad) );
    
    load->type = type;
    load->name = name;
    load->location = location;
    
    stmt->args = load;
    
    return stmt;
    
}

void ll_stmt_load_destroy(LLStmtLoad *load) {
    
    // Destroy the type.
    ll_type_destroy(load->type);
    
    // Free the name.
    free(load->name);
    
    // Destroy the location.
    ll_lvalue_destroy(load->location);
    
    // Free the instance itself.
    free(load);
    
}

char *ll_stmt_load_description(LLStmtLoad *load) {
    
    // <name>
    MutableString *mstr = mutable_string_init(load->name, do_not_take_ownership);
    
    // " : "
    mutable_string_concatenate(mstr, " : ", do_not_take_ownership);
    
    // <type>
    char *typeDesc = ll_type_description(load->type);
    mutable_string_concatenate(mstr, typeDesc, take_ownership);
    
    // " from "
    mutable_string_concatenate(mstr, " from ", do_not_take_ownership);
    
    // <location>
    char *locationDesc = ll_lvalue_description(load->location);
    mutable_string_concatenate(mstr, locationDesc, take_ownership);
    
    // Extract & destroy
    return mutable_string_destroy_extract_buffer(mstr);
    
}
