# Types

LLMM provides a few of the most frequently used types built into the IR.
- `i1`: A single bit.
- `i8`: An 8-bit integer (signed).
- `i16`: A 16-bit integer (signed).
- `i32`: A 32-bit integer (signed).
- `flt`: A 32-bit floating-point number.

The IR also allows some derived types. For example, a pointer to a type `T` can be declared as `T*` for an arbitrary type `T`.

In addition, types can be bundled together. This example corresponds to a high-level `struct` whose first two fields are 16-bit integers, third field is a single bit (e.g. a bool) and fourth field is a pointer to a float. `T` must be a valid type name.
```
type T = { i16, i16, i1, flt* }
```
Members are referred to by index (0 refers to the first element, and 3 refers to the last element in this example).

Valid types match the regex `[a-zA-Z][a-zA-Z0-9_]*\**`. They start with a letter, followed by an arbitrary number of letters or numbers, and then an arbitrary number of stars (`*`).