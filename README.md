# ooswsys light core ANSI89

Tiny object-oriented programming system for ANSI C89/C90.

This is an educational tutorial project about object-oriented programming in C. It shows how a tiny object system can be built in plain C with objects, class descriptors, constructors, destructors, inheritance-like base/derived layout, and virtual-method-style function pointers.

The project intentionally avoids generator code, metadata tables, datatype experiments, diagrams, and larger framework features. Those belong in the later full repository.

## What You Will Learn

- How to model objects and classes in C89/C90.
- How to write constructor and destructor functions in C.
- How to represent inheritance-like behavior with struct layout.
- How to use function pointers as virtual methods.
- How one small OOP/OOM pattern can be repeated for multiple classes.

Search terms: OOP in C, object-oriented C, ANSI C object system, C89 OOP, C90 OOP, virtual methods in C, constructors and destructors in C.

## What Is Included

- `core/inc/object_.h` and `core/src/object_.c`: the reusable OOM runtime core.
- `app/inc/object_a1.h` and `app/src/object_a1.c`: one derived example class.
- `app/inc/object_b1.h` and `app/src/object_b1.c`: a second derived example class with the same pattern but different fields.
- `app/main.c`: small runnable demo.
- `Makefile`: strict ANSI C build recipe.
- `.vscode/`: portable editor tasks and C configuration.

## Repository Shape

```text
core/
  inc/object_.h
  src/object_.c

app/
  inc/object_a1.h
  inc/object_b1.h
  src/object_a1.c
  src/object_b1.c
  main.c
```

`ObjectA1` and `ObjectB1` are intentionally outside `core/`. They are demo classes that show how to use the object model, not part of the reusable runtime itself.

## Build

```sh
make all
```

Or build directly:

```sh
gcc -Wall -Wextra -Wcast-qual -Wwrite-strings -ansi -pedantic -I . app/main.c core/src/object_.c app/src/object_a1.c app/src/object_b1.c -o obj/Debug/ooswsys_light_core.exe
```

## Run

```sh
make run
```

The demo prints constructor order, object sizes, member values, virtual method output, and destructor order.

## Tutorial Path

Start with the files in this order:

1. `core/inc/object_.h`: base object and class descriptor.
2. `core/src/object_.c`: `new_`, `delete_`, and base lifecycle.
3. `app/inc/object_a1.h` and `app/src/object_a1.c`: first example class.
4. `app/inc/object_b1.h` and `app/src/object_b1.c`: second example class with different fields.
5. `app/main.c`: runnable demonstration.

## Core Ideas

- A derived object starts with its base object member.
- A class descriptor stores object size and lifecycle function pointers.
- Objects keep a read-only pointer to their class descriptor.
- `new_` allocates the requested class size and calls its constructor.
- `delete_` calls the object's class destructor and releases the memory.
- Derived constructors call the base constructor before initializing derived fields.
- Derived destructors clean derived behavior before calling the base destructor.
- Adding another class follows the same shape: object struct, ctor params, class struct, make/drop functions, constructor, destructor, and virtual method pointers. The fields and class-owned data can still differ.

## Style

The formatting is intentional. It favors visible structure, wide spacing, and explicit C89-compatible code over compact style. Please do not run automatic formatters over the hand-written C files.

## License

Licensed under the Apache License, Version 2.0.

Copyright 2026 Jakub Stulir.

Original author: Jakub Stulir.
Aliases/brands: VirtueTronic, Sob Rascal James.

See `LICENSE` and `NOTICE`.
