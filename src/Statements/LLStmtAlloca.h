
#pragma once

#include "../Shared/LLType.h"

#include "LLStmt.h"

// alloca name : T

typedef struct {
    
    char *name;
    LLType *type;
    
} LLStmtAlloca;

LLStmt *ll_stmt_init_alloca(char *name, LLType *type);

void ll_stmt_alloca_destroy(LLStmtAlloca *stmt);