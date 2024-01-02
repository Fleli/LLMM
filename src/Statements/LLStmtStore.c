
#include <stdlib.h>

#include "../IR/LLStmt.h"
#include "../IR/LLType.h"
#include "../IR/LLLValue.h"
#include "../IR/LLRValue.h"
#include "../IR/LLStmtStore.h"

LLStmt *ll_stmt_init_store(LLRValue *value, LLType *type, LLLValue *location) {
    
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
    
    // Destroy the value (RValue) and location (LValue).
    ll_rvalue_destroy(store->value);
    ll_lvalue_destroy(store->location);
    
    // Free the `store` instance.
    free(store);
    
}

char *ll_stmt_store_description(LLStmtStore *store) {
    
    // <value>
    char *valStr = ll_rvalue_description(store->value);
    MutableString *mstr = mutable_string_init(valStr, take_ownership);
    
    // " : "
    mutable_string_concatenate(mstr, " : ", do_not_take_ownership);
    
    // <type>
    char *typeDesc = ll_type_description(store->type);
    mutable_string_concatenate(mstr, typeDesc, take_ownership);
    
    // " at "
    mutable_string_concatenate(mstr, " at ", do_not_take_ownership);
    
    // <location>
    char *locationDesc = ll_lvalue_description(store->location);
    mutable_string_concatenate(mstr, locationDesc, take_ownership);
    
    // Extract & destroy
    return mutable_string_destroy_extract_buffer(mstr);
    
}
