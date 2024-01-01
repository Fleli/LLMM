
#include <stdlib.h>

#include "../IR/LLStmt.h"
#include "../IR/LLType.h"
#include "../IR/LLRValue.h"
#include "../IR/LLStmtStore.h"

LLStmt *ll_stmt_init_store(LLType *type, LLRValue *value, LLRValue *location) {
    
    LLStmt *stmt = malloc( sizeof(LLStmt) );
    
    stmt->mnemonic = heap_string("store");
    
    LLStmtStore *store = malloc( sizeof(LLStmtStore) );
    
    store->type = type;
    store->value = value;
    store->location = location;
    
    stmt->args = store;
    
    return stmt;
    
}

void ll_stmt_store_destroy(LLStmtStore *store) {
    
    // Destroy the type.
    ll_type_destroy(store->type);
    
    // TODO: Update this if an LValue type is introduced.
    // Destroy the value and location (both are RValues).
    ll_rvalue_destroy(store->value);
    ll_rvalue_destroy(store->location);
    
    // Free the `store` instance.
    free(store);
    
}
