
#pragma once

#include "LLType.h"
#include "LLStmt.h"

// Usage: `alloca <type> <name>;`

/* The name and type of a stack-allocated variable. */
typedef struct {
    
    LLType *type;
    char *name;
    
} LLStmtAlloca;

/* Initializa an alloca statement from a type and name. Takes ownership of both arguments. */
LLStmt *ll_stmt_init_alloca(char *name, LLType *type);

/* Destroy the satellite data (`LLStmtAlloca`) of an alloca statement. */
void ll_stmt_alloca_destroy(LLStmtAlloca *alloca);
