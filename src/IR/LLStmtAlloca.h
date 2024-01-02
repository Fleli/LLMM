
#pragma once

#include "LLType.h"
#include "LLStmt.h"



/* 
An `alloca` statement contains a name and type of a stack-allocated variable.
Usage: `alloca <name> : <type> ;`
*/
typedef struct {
    
    char *name;
    LLType *type;
    
} LLStmtAlloca;

/* Initializa an alloca statement from a type and name. Takes ownership of both arguments. */
LLStmt *ll_stmt_init_alloca(char *name, LLType *type);

/* Destroy the satellite data (`LLStmtAlloca`) of an alloca statement. */
void ll_stmt_alloca_destroy(LLStmtAlloca *alloca);

/* Build a description out of an `alloca` statement. */
char *ll_stmt_alloca_description(LLStmtAlloca *alloca);
