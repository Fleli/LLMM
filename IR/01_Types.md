# Types

LLMM provides a few of the most frequently used types built into the IR.
- `bit`: A single bit.
- `w8`: An 8-bit word.
- `w16`: A 16-bit word.
- `float`: A 32-bit floating-point number.

The IR also allows some derived types. For example, a pointer to a type `T` can be declared as `T*` for an arbitrary type `T`.

In addition, types can be bundled together. This example corresponds to a high-level `struct` whose first two fields are 16-bit integers, third field is a single bit (e.g. a bool) and third field is a pointer to a float. `T` must be a valid type name.
```
type T = { w16, w16, bit, float* }
```
Members are referred to by index (0 refers to the first element, and 3 refers to the last element in this example).

Valid types match the regex `[a-zA-Z][a-zA-Z0-9_]*\**`. They start with a letter, followed by an arbitrary number of letters or numbers, and then an arbitrary number of stars (`*`).