
#pragma once

#include "../DataStructures/Array.h"

#include "../Statements/LLStmt.h"

/* A label is an ordered list of statements. Together, several labels make up a function. */
typedef struct {
    
    char *name;
    Array *statements;
    
} LLLabel;

/* Initialize a new `LLLabel` instance. The new label takes ownership of the `nane` string.*/
LLLabel *ll_label_init(char *name);

/* Append a statement to a label. */
void ll_label_add_statement(LLLabel *label, LLStmt *stmt);
