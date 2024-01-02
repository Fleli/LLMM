
#pragma once

/* Perform runtime checks to verify well-formedness, e.g. array indices within bounds, etc. */
#define DEBUG

/* 
Produce a comprehensive list of all objects created at runtime. 
Will print object type and address upon initialization.
Not used on all types. More types may define this later, if the debugging requires it.
*/
#define PRINTOBJECTS
