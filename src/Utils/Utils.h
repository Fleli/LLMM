
#pragma once

/* 
A `MutableString` is a `char *` wrapper that helps string concatenation run in O(n).
Concatenation of two strings requires O(a + b) time for lengths a, b of the input strings.

Often, with inputs `char *x` and `char *y`, just enough space is allocated for the concatenation. 
This may lead to frequent `realloc`s, resulting in worst-case performance of O(n^2). By 
exponentially increasing the capacity, we get closer to O(n) worst-case performance.
*/
typedef struct {
    
    /* The size of the block allocated for the character buffer. */
    int capacity;
    
    /* The length of the string stored, including the null terminator. */
    int length;
    
    /* The `buffer` is a pointer to the actual characters in the string. */
    char *buffer;
    
} MutableString;

/* Initialize a mutable string from a plain `char *` string. Will take ownership of the given `char *` if requested to do so. */
MutableString *mutable_string_init(char *string, int take_ownership);

/* Append a `char *` to a mutable string. Take ownership of the `other` string if requested to do so. */
void mutable_string_concatenate(MutableString *base, char *other, int take_ownership);

/* Destroy a mutable string and all data owned by it. */
void mutable_string_destroy(MutableString *mut_str);

/* Copy a string, e.g. a literal, to the heap and return a pointer to the new string. */
char *heap_string(char* literal);
