# Intermediate Representation Structure

The top level of the structure contains all function declarations, type definitions, and metadata (once it is added to the IR).

## Functions

Functions, `LLFunction`, are the most important part of the IR. They contain the actual code to be executed.

Function bodies are organized into _labels_, `LLLabel`. A label is a group of code with no branches, except at the end. In other words, a label represents a basic block.

## Type Definitions

The top level also contains type definitions. These are further explained in `01_Types.md`.

## Metadata

Metadata support will be added to the IR later on. This will allow debugging info (filenames and line & col numbers), author names, target platforms, etc. 
