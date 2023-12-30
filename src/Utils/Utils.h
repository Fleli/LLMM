
#pragma once

/* Copy a string, e.g. a literal, to the heap and return a pointer to the new string. */
char *heap_string(char* literal);

/* Return a pointer to the concatenation of two strings `a` and `b`. */
char *string_concatenate(char *a, char *b);
