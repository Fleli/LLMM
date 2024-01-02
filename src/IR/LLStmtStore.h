
#pragma once

#include "LLStmt.h"
#include "LLType.h"
#include "LLLValue.h"
#include "LLRValue.h"

/* 
The type, value and location of a store statement. 
Usage: `store <value> : <type> at <location> ;`
*/
typedef struct {
    
    /* The value to store (RValue). */
    LLRValue *value;
    
    /* The type of the value to store (so the LValue is a pointer to this type). */
    LLType *type;
    
    /* The location (LValue) at which to store the value. */
    LLLValue *location;
    
} LLStmtStore;

/* Initialize a `store` statement from a type (to store), a value (to store) and a location (at which to store). */
LLStmt *ll_stmt_init_store(LLRValue *value, LLType *type, LLLValue *location);

/* Destroy a `LLStmtStore` instance. */
void ll_stmt_store_destroy(LLStmtStore *store);

/* Build a description of an `LLStmtStore` instance. */
char *ll_stmt_store_description(LLStmtStore *store);
