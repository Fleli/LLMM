
#include <stdlib.h>
#include <stdio.h>

#include "../meta.h"

#include "Array.h"

Array *array_init(void) {
    return array_init_with_initial_capacity(1);
}

Array *array_init_with_initial_capacity(int initialCapacity) {
    
    #ifdef DEBUG
    if (initialCapacity <= 0) {
        printf("Cannot initialize array of size %d <= 0.\n", initialCapacity);
        exit(1);
    }
    #endif
    
    Array *a = malloc( sizeof(Array) );
    
    a->count = 0;
    a->length = initialCapacity;
    a->data = malloc( (a->length) * sizeof(void*) );
    
    return a;
    
}

// Maintained invariant: .count < .length, always.
// The insert method automatically adjusts the array size after insertion if this invariant fails.
void array_insert(Array *a, void *newElement, int index) {
    
    #ifdef DEBUG
    if (index < 0 || index > a->count) {
        printf("Cannot insert element at index %d, with array count %d.\n", index, a->count);
        exit(1);
    }
    #endif
    
    // Move all elements after the insertion index one place to the right.
    int newLocation = a->count;
    while (newLocation > index) {
        (a->data)[newLocation] = (a->data)[newLocation - 1];
        newLocation -= 1;
    }
    
    (a->data)[index] = newElement;
    
    a->count += 1;
    
    if (a->count == a->length) {
        a->length *= 2;
        a->data = realloc(a->data, (a->length) * sizeof(void*) );
    }
    
}

void array_append(Array *a, void *newElement) {
    array_insert(a, newElement, a->count);
}

void* array_get(Array *a, int index) {
    
    #ifdef DEBUG
    if (index < 0 || index >= a->count) {
        printf("Index %d out of bounds for array with count %d.\n", index, a->count);
        exit(1);
    }
    #endif
    
    return (a->data)[index];
    
}
