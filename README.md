# OBJ Parser Library

Simple C++ parsing libary for .obj files

### Building the library

Simply go to the root of the repository and invoke `make`.
Invoke `make clean` to remove both `.o` and `.so`.

### Work Done

This project is on-going. The parser does not handle the whole .obj syntax,
and does not deal well with incorrect formats either.

### What's handled

- `v`
- `vt`
- `f v1 v2 v3`
- `f v1/vt1 v2/vt2 v3/vt3`
- `f v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3`
- comments

### Work to do

- mtl parsing
- Handle `vn`
- Handle `o`
- Handle `g`
