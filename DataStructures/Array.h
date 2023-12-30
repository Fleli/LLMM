
typedef struct Array_T {
    
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
Maintained invariant: .count < .length, always.
The insert method automatically adjusts the array size after insertion if this invariant fails.
*/
void array_insert(Array *a, void *newElement, int index);

/* Destroy an array and free the memory it uses. Will *NOT* destroy remaining elements. */
void array_destroy(Array *a);
