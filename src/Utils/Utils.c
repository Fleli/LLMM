
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *heap_string(char* literal) {
    
    // Allocate space for the string, including the null character.
    char *str = malloc( (strlen(literal) + 1) * sizeof(char) );
    
    return strcpy(str, literal);
    
}

char *string_concatenate(char *a, char *b) {
    
    int aLength = strlen(a);
    int bLength = strlen(b);
    
    // aLength and bLength indicate lengths, excluding the terminator 0.
    // Thus, the length including it is aLength + bLength + 1.
    char *result = malloc( (aLength + bLength + 1) * sizeof(char) );
    
    // We copy the whole a-string
    for (int i = 0 ; i < aLength ; i++) {
        result[i] = a[i];
    }
    
    // Then we copy the whole b-string
    for (int i = 0 ; i < bLength ; i++) {
        result[i + aLength] = b[i];
    }
    
    // Finally, we terminate the string with a 0.
    result[aLength + bLength] = 0;
    
    return result;
    
}
