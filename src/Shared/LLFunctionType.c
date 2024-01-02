
#include <stdlib.h>

#include "../Utils/Utils.h"

#include "../IR/LLType.h"
#include "../IR/LLFunctionType.h"

LLFunctionType *ll_function_type_init(LLType *input, LLType *output) {
    
    LLFunctionType *ftype = malloc( sizeof(LLFunctionType) );
    
    ftype->input = input;
    ftype->output = output;
    
    return ftype;
    
}

void ll_function_type_destroy(LLFunctionType *ftype) {
    
    // Destroy the underlying input and output types.
    ll_type_destroy(ftype->input);
    ll_type_destroy(ftype->output);
    
    // Destroy the `ftype` instance itself.
    free(ftype);
    
}

char *ll_function_type_description(LLFunctionType *ftype) {
    
    // Create a mutable string with an opening parenthesis.
    MutableString *mstring = mutable_string_init("(", do_not_take_ownership);
    
    // Create descriptions of input and output type.
    char *in_description = ll_type_description(ftype->input);
    char *out_description = ll_type_description(ftype->output);
    
    // Append in, ->, out, )
    mutable_string_concatenate(mstring, in_description, take_ownership);
    mutable_string_concatenate(mstring, " -> ", do_not_take_ownership);
    mutable_string_concatenate(mstring, out_description, take_ownership);
    mutable_string_concatenate(mstring, ")", do_not_take_ownership);
    
    // Return the function type, `(in -> out)`.
    return mutable_string_destroy_extract_buffer(mstring);
    
}
