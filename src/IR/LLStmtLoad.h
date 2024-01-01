
#pragma once

#include "LLType.h"
#include "LLStmt.h"
#include "LLRValue.h"

// Usage: `load <type> <name> from <location> ;`

/* The name and type of a stack-allocated variable. */
typedef struct {
    
    LLType *type;
    char *name;
    LLRValue *location;
    
} LLStmtLoad;

/* Initialize a `load` statement instance with a given type, name and location. Takes ownership of all of these. */
LLStmt *ll_stmt_init_load(LLType *type, char *name, LLRValue *location);

/* Destroy the satellite data (`LLStmtLoad`) of a load statement. */
void ll_stmt_load_destroy(LLStmtLoad *load);
