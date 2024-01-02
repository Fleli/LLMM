
#include "meta.h"

#include "IR/LLFunction.h"
#include "IR/LLParameter.h"
#include "IR/LLType.h"
#include "IR/LLFunctionType.h"
#include "IR/LLStmt.h"
#include "IR/LLStmtAlloca.h"
#include "IR/LLStmtLoad.h"
#include "IR/LLStmtStore.h"

#include "Utils/Utils.h"

void test1() {
    
    char *funcName = heap_string("do_something");
    LLFunction *func = ll_function_init(funcName);
    
    char *p1Name = heap_string("x");
    LLType *p1Type = ll_type_init(ll_type_i16, NULL);
    LLParameter *p1 = ll_parameter_init(p1Name, p1Type);
    ll_function_add_parameter(func, p1);
    
    char *p2Name = heap_string("y");
    LLType *in = ll_type_init(ll_type_i16, NULL);
    LLType *out = ll_type_init(ll_type_flt, NULL);
    LLFunctionType *llft = ll_function_type_init(in, out);
    LLType *p2Type = ll_type_init(ll_type_function, llft);
    LLParameter *p2 = ll_parameter_init(p2Name, p2Type);
    ll_function_add_parameter(func, p2);
    
    char *desc = ll_function_description(func);
    
    printf("%s\n", desc);
    
    free(desc);
    ll_function_destroy(func);
    
}

void test2() {
    
    LLFunction *func = ll_function_init(heap_string("test2"));
    
    LLLabel *label = ll_label_init(heap_string("@some_label"));
    
    ll_label_add_statement(label, ll_stmt_init_alloca(heap_string("m3"), ll_type_init(ll_type_i16, NULL)));
    // ll_label_add_statement(label, ll_stmt_init_load(heap_string("%%2"), ll_type_init(ll_type_i16, NULL), ll_lvalue_init(ll_lvalue_variable, heap_string("%%1"))));
    
    ll_function_add_label(func, label);
    
    char *desc = ll_label_description(label);
    
    printf("%s\n", desc);
    
    free(desc);
    ll_function_destroy(func);
    
}

int main() {
    
    test1();
    test2();
    
    return 0;
    
}

