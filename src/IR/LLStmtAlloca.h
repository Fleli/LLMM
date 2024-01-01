
#pragma once

#include "LLType.h"
#include "LLStmt.h"

// Usage: `alloca <type> <name>;`

/* The name and type of a stack-allocated variable. */
typedef struct {
    
    LLType *type;
    char *name;
    
} LLStmtAlloca;

LLStmt *ll_stmt_init_alloca(char *name, LLType *type);

void ll_stmt_alloca_destroy(LLStmtAlloca *stmt);
