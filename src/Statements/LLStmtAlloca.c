
#include <stdlib.h>

#include "../Shared/LLType.h"

#include "../Utils/Utils.h"

#include "LLStmt.h"
#include "LLStmtAlloca.h"

LLStmt *ll_stmt_init_alloca(char *name, LLType *type) {
    
    LLStmt *stmt = malloc( sizeof(LLStmt) );
    
    stmt->mnemonic = heap_string("alloca");
    
    LLStmtAlloca *alloca = malloc( sizeof(LLStmtAlloca) );
    
    alloca->name = name;
    alloca->type = type;
    
    return stmt;
    
}

/*
Free the memory allocated by the LLStmt's satellite data (name and type), and the struct holding them.
*/

void ll_stmt_alloca_destroy(LLStmtAlloca *alloca) {
    
    // Free the memory holding the variable name.
    free(alloca->name);
    
    // Free the memory taken up by the type information.
    ll_type_destroy(alloca->type);
    
    // Free the `alloca` itself
    free(alloca);
    
}