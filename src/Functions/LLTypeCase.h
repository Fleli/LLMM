
#pragma once

/* Represents a case of an `LLType`. */
typedef int LLTypeCase;

/* The `i1` (1-bit integer) `LLType` case. */
#define ll_type_i1 1

/* The `i8` (8-bit integer) `LLType` case. */
#define ll_type_i8 2

/* The `i16` (16-bit integer) `LLType` case. */
#define ll_type_i16 3

/* The `float` (16-bit float) `LLType` case. */
#define ll_type_flt 10

/* The `ptr` (pointer) `LLType` case. Expects an underlying type as associated value as well. */
#define ll_type_ptr 20

/* The `struct` (struct) `LLType` case. Expects an array of underlying types as associated value as well. */
#define ll_type_struct 21
