
#include <stdlib.h>
#include <string.h>

#include "../IR/LLStmt.h"
#include "../IR/LLStmtAlloca.h"

void ll_stmt_destroy(LLStmt *stmt) {
    
    // We destroy different statement types differently. So we investigate what the mnemonic is, and choose the appropriate destructor.
    
    char *mnemonic = stmt->mnemonic;
    
    if (strcmp(mnemonic, "alloca") == 0) {
        ll_stmt_alloca_destroy(stmt->args);
    }
    
    // Free the mnemonic string.
    free(stmt->mnemonic);
    
    // Free the statement itself.
    free(stmt);
    
}
