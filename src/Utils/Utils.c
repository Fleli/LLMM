
#include <stdlib.h>
#include <string.h>

char *heap_string(char* literal) {
    
    char *str = malloc( strlen(literal) * sizeof(char) );
    
    return strcpy(str, literal);
    
}
