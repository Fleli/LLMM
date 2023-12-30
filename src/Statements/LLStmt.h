
#pragma once

/* An LLStmt represents a generic statement in an LLLabel. */
typedef struct {
    
    /* The `name` of an LLStmt is like the mnemonic of an assembly instruction. Examples are `decl` and `branch`. */
    char *name;
    
    /* The `args` property is used to attach extra data to a statement, e.g. the variable to declare, the label to branch to, etc. */
    void *args;
    
} LLStmt;
