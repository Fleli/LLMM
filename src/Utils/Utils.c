
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Utils.h"

char *heap_string(char* literal) {
    
    // Allocate space for the string, including the null character.
    char *str = malloc( (strlen(literal) + 1) * sizeof(char) );
    
    return strcpy(str, literal);
    
}

MutableString *mutable_string_init(char *string, int take_ownership_of_other) {
    
    MutableString *mut_string = malloc( sizeof(MutableString) );
    
    int lengthIncludingTerminator = strlen(string) + 1;
    
    if (take_ownership_of_other) {
        mut_string->buffer = string;
    } else {
        mut_string->buffer = malloc( lengthIncludingTerminator * sizeof(char) );
        strcpy(mut_string->buffer, string);
    }
    
    mut_string->length = lengthIncludingTerminator;
    mut_string->capacity = lengthIncludingTerminator;
    
    return mut_string;
    
}

void mutable_string_concatenate(MutableString *base, char *other, int take_ownership_of_other) {
    
    int otherLength = strlen(other);
    int new_length = base->length + otherLength;
    
    if (new_length > base->capacity) {
        base->capacity = new_length * 2;
        base->buffer = realloc(base->buffer, base->capacity);
    }
    
    // We calculate a pointer to the base's null character
    char* address_of_null_of_base = base->buffer + base->length - 1;
    
    // Then, we copy the other string into it.
    strcpy(address_of_null_of_base, other);
    
    // We then update the length of the mutable string
    base->length += otherLength;
    
    // If requested to take ownership of `other`, we simply destroy it since we have already copied its contents.
    if (take_ownership_of_other) {
        free(other);
    }
    
}

void mutable_string_destroy(MutableString *mut_str) {
    
    // Destroy the whole mutable string, except the buffer.
    char *buffer = mutable_string_destroy_extract_buffer(mut_str);
    
    // Destroy the buffer as well.
    free(buffer);
    
}

char *mutable_string_destroy_extract_buffer(MutableString *mut_str) {
    
    // Retain the buffer.
    char *buffer = mut_str->buffer;
    
    // Free the mutable string.
    free(mut_str);
    
    // Return the buffer.
    return buffer;
    
}
