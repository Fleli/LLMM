
#pragma once

#include "LLType.h"
#include "LLStmt.h"
#include "LLLValue.h"

/* 
The name and type of a stack-allocated variable. 
Usage: `load <name> : <type> from <location> ;`
*/
typedef struct {
    
    char *name;
    LLType *type;
    LLLValue *location;
    
} LLStmtLoad;

/* Initialize a `load` statement instance with a given name, type, and location. Takes ownership of all of these. */
LLStmt *ll_stmt_init_load(char *name, LLType *type, LLLValue *location);

/* Destroy the satellite data (`LLStmtLoad`) of a load statement. */
void ll_stmt_load_destroy(LLStmtLoad *load);

/* Build a description of an `LLStmtLoad` instance. */
char *ll_stmt_load_description(LLStmtLoad *load);
