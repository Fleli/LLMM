
#include <stdlib.h>

#include "../Utils/Utils.h"

#include "../IR/LLType.h"
#include "../IR/LLStmt.h"
#include "../IR/LLStmtAlloca.h"

LLStmt *ll_stmt_init_alloca(char *name, LLType *type) {
    
    LLStmt *stmt = malloc( sizeof(LLStmt) );
    
    stmt->mnemonic = heap_string("alloca");
    
    LLStmtAlloca *alloca = malloc( sizeof(LLStmtAlloca) );
    
    alloca->name = name;
    alloca->type = type;
    
    stmt->args = alloca;
    
    return stmt;
    
}

void ll_stmt_alloca_destroy(LLStmtAlloca *alloca) {
    
    // Free the memory holding the variable name.
    free(alloca->name);
    
    // Free the memory taken up by the type information.
    ll_type_destroy(alloca->type);
    
    // Free the `alloca` itself
    free(alloca);
    
}

char *ll_stmt_alloca_description(LLStmtAlloca *alloca) {
    
}
