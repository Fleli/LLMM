
#include <stdlib.h>
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
    }
    
    // Free the mnemonic string.
    free(stmt->mnemonic);
    
    // Free the statement itself.
    free(stmt);
    
}
