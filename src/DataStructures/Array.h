
/* 
An array holding pointers to elements. The array does not "own" the elements, so it
won't deallocate the memory used by elements when being destroyed.
*/
typedef struct {
    
    int count;
    int length;
    
    void **data;
    
} Array;

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
