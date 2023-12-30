
#pragma once

/* An LLStmt represents a generic statement in an LLLabel. */
typedef struct {
    
    /* The `mnemonic` of an LLStmt is like the mnemonic of an assembly instruction. Examples are `alloca` and `branch`. */
    char *mnemonic;
    
    /* The `args` property is used to attach extra data to a statement, e.g. the variable to declare, the label to branch to, etc. */
    void *args;
    
} LLStmt;

/* Destroy a `LLStmt` instance and free its memory. */
void ll_stmt_destroy(LLStmt *stmt);
