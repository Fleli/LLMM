
#pragma once

/* 
An array holding pointers to elements. The array does not "own" the elements, so it
won't deallocate the memory used by elements when being destroyed.
*/
typedef struct {
    
    int count;
    int length;
    
    void **data;
    
} Array;

/* Destructors are `void` functions that take a pointer to the object they are destroying. */
#define Destructor void (*) (void*)

/* Initialize an array and return a pointer to it. */
Array* array_init(void);

/* Initialize an array and return a pointer to it. Reserve an initial capacity. */
Array* array_init_with_initial_capacity(int initialCapacity);

/* Append a new element to an array. */
void array_append(Array *a, void *newElement);

/*
Insert a new element at a certain index. 
*/
void array_insert(Array *a, void *newElement, int index);

/* Get the element at a certain index. */
void* array_get(Array *a, int index);

/* Get the number of elements in the array. */
int array_count(Array *a);

/* 
Destroy the array and free the memory it uses.
Since arrays don't necessarily take ownership of elements, each element should be destroyed externally first.
*/
void array_destroy(Array *a);

/*
Destroy the array and free the memory it uses.
Assume that the array has ownership of its elements, and pass a function to destroy each element.
*/
void array_destroy_with_ownership(Array *a, void (*destructor_function)(void *element));

/*
Build a description of the array by applying a given description function on each element.
Will use commas to separate each element.
Will not enclose in `[]`.
*/
char *array_list_description(Array *a, char *(*elementDescription)(void *element));
