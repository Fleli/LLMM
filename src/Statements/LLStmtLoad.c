
#include <stdlib.h>

#include "../Utils/Utils.h"

#include "../IR/LLStmt.h"
#include "../IR/LLType.h"
#include "../IR/LLRValue.h"
#include "../IR/LLStmtLoad.h"

LLStmt *ll_stmt_init_load(LLType *type, char *name, LLRValue *location) {
    
    LLStmt *stmt = malloc( sizeof(LLStmt) );
    
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
    ll_rvalue_destroy(load->location);
    
    // Free the instance itself.
    free(load);
    
}
