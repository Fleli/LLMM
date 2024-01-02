
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../IR/LLStmt.h"

#include "../IR/LLStmtAlloca.h"
#include "../IR/LLStmtLoad.h"
#include "../IR/LLStmtStore.h"

void ll_stmt_destroy(LLStmt *stmt) {
    
    // We destroy different statement types differently. So we investigate what the mnemonic is, and choose the appropriate destructor.
    
    char *mnemonic = stmt->mnemonic;
    void *associated_value = stmt->args;
    
    if (strcmp(mnemonic, "alloca") == 0) {
        ll_stmt_alloca_destroy(associated_value);
    } else if (strcmp(mnemonic, "load") == 0) {
        ll_stmt_load_destroy(associated_value);
    } else if (strcmp(mnemonic, "store") == 0) {
        ll_stmt_store_destroy(associated_value);
    } else {
        printf("Statement %s not implemented.", mnemonic);
        exit(1);
    }
    
    // Free the mnemonic string.
    free(stmt->mnemonic);
    
    // Free the statement itself.
    free(stmt);
    
}

char *ll_stmt_description(LLStmt *stmt) {
    
    // Start with the mnemonic
    MutableString *mstr = mutable_string_init(stmt->mnemonic, do_not_take_ownership);
    
    // Add a space.
    mutable_string_concatenate(mstr, " ", do_not_take_ownership);
    
    // Then get the "specialized" description.
    char *mnemonic = stmt->mnemonic;
    
    if (strcmp(mnemonic, "alloca") == 0) {
        mutable_string_concatenate(mstr, ll_stmt_alloca_description(stmt->args), take_ownership);
    } else if (strcmp(mnemonic, "load") == 0) {
        mutable_string_concatenate(mstr, ll_stmt_load_description(stmt->args), take_ownership);
    } else if (strcmp(mnemonic, "store") == 0) {
        mutable_string_concatenate(mstr, ll_stmt_store_description(stmt->args), take_ownership);
    } else {
        printf("Statement %s not implemented.", mnemonic);
        exit(1);
    }
    
    return mutable_string_destroy_extract_buffer(mstr);
    
}
