
#include "DataStructures/Array.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
    
    Array *a = array_init();
    
    void *elem1 = malloc(sizeof(int));
    *(int*)(elem1) = 5;
    array_insert(a, elem1, 0);
    
    void *elem2 = malloc(sizeof(int));
    *(int*)(elem2) = 7;
    array_insert(a, elem2, 0);
    
    int u = * (int*) array_get(a, 0);
    printf("u = %d\n", u);
    
    int v = * (int*) array_get(a, 1);
    printf("v = %d\n", v);
    
    return 0;
    
}
