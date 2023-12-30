# Destructors

I like to define "destructors" for different data structures.

For a struct `T`, I usually define

`void T_destroy(T *instance);`

I've decided these functions almost always have the following responsibilities:
- Destroy all allocated data contained in this structure (possibly recursively destroying entire trees of data).
- Free the `instance` of `T` itself.

There is an important exception to the first rule:
- If the `T` instance does not have ownership of the data it refers to, it should not destroy it. This will be clearly stated in the Doxygen comments above the destructor functions. Arrays don't necessarily have ownership of their elements.
