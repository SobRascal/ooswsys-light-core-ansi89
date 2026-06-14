# Agent Notes

This is the minimal educational core repository for `ooswsys_light`.

Prefer reviewing and editing hand-written C89/C90 source in `core/` and `app/`.
Keep `core/` limited to the reusable OOM runtime.
Keep demo classes and runnable examples in `app/`.
Do not add generator, metadata, datatype, diagram, or binary output folders to this repository.
Do not inspect generated binaries or object files.
Preserve `LICENSE`, `NOTICE`, and existing SPDX/copyright headers.

Use these strict GCC flags when checking changes:

```sh
gcc -Wall -Wextra -Wcast-qual -Wwrite-strings -ansi -pedantic -I . app/main.c core/src/object_.c app/src/object_a1.c app/src/object_b1.c -o obj/Debug/ooswsys_light_core.exe
```

The same build recipe is also captured in `Makefile`.
Use `make all` when GNU make is available.

## C Formatting Convention

Preserve the existing hand-written C formatting style.

- Do not run automatic formatters on `core/` or `app/`.
- Keep the wide vertical spacing between declarations, logic blocks, and returns.
- Keep braces on the same line for functions and control blocks, matching existing files.
- Keep spaces inside calls and expressions, for example:
  `new_ ( classObject, args )`
  `object_ -> classObject`
  `makeClassObject . makeClass ( )`
- Preserve aligned struct fields, function pointers, and multi-line parameter lists.
- Prefer explicit, readable C89 style over compact modern C style.
- Declare variables near the top of functions and blocks, compatible with ANSI C89/C90.
- When editing existing code, match nearby spacing first. Consistency is more important than personal style.
- Do not rewrite unrelated formatting while making logic changes.
- Comments should be rare and useful; avoid noisy comments that repeat the code.
- Preserve the short SPDX and copyright header comments at the top of source files.

## OOM/OOP C Style

This project uses an intentional object-oriented model in ANSI C.

- Keep base object/class members first in derived structs.
- Keep constructor/destructor order explicit: base constructor before derived constructor, derived destructor before base destructor.
- Preserve `Object_`, `ClassObject`, `CtorParams`, `makeClass...`, `new_`, and `delete_` naming conventions.
- Preserve const-correct API boundaries: objects read class descriptors through `struct ClassObject const *`; ownership/freeing APIs keep mutable pointers where needed.
- Prefer small, explicit lifecycle checks over hidden helper magic.
