
#pragma once

#include "../DataStructures/Array.h"

#include "LLStmt.h"

/* A label is an ordered list of statements. Together, several labels make up a function. */
typedef struct {
    
    char *name;
    Array *statements;
    
} LLLabel;

/* Initialize a new `LLLabel` instance. The new label takes ownership of the `nane` string.*/
LLLabel *ll_label_init(char *name);

/* Append a statement to a label. */
void ll_label_add_statement(LLLabel *label, LLStmt *stmt);

/* Destroy a label and all statements contained in it. */
void ll_label_destroy(LLLabel *label);

/* 
Build a description of the label. 
Will indent the label name once, and its statements twice:
*/
char *ll_label_description(LLLabel *label);
