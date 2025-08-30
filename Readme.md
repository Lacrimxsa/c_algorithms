Euclides GCD – Build and Debug with Makefile
============================================

This project demonstrates:
- A single Makefile that works with both gcc and clang.
- Different build profiles (debug, release, asan).
- Integration with sanitizers (ASan/UBSan).
- Running under Valgrind.
- Coverage reporting with gcov/lcov.
- How to use gdb to debug step by step.

Requirements
------------
On Debian/Ubuntu:
  sudo apt update
  sudo apt install build-essential gcc clang clangd gdb valgrind gcov lcov

Notes:
- clangd is the Language Server Protocol (LSP) used by editors like NeoVim and VSCode.
- It works perfectly on Linux (not only on macOS).

Basic usage
-----------
Build with gcc (default):
  make

Build with clang:
  make CC=clang

Run the program:
  ./bin/im_the_exec 1071 462

Clean build artifacts:
  make clean

Build profiles
--------------
Debug build (no optimizations, with debug symbols):
  make debug

Release build (optimized, without debug info):
  make release

With sanitizers (detects memory errors and undefined behavior):
  make asan
  ./bin/im_the_exec 1071 462

Valgrind
--------
  make debug
  make run-valgrind ARGS="1071 462"

Coverage
--------
Compile with coverage instrumentation:
  make coverage
Run the program:
  ./bin/im_the_exec 54 24
Generate HTML report:
  make report-coverage
Open coverage/index.html in your browser.

Debugging with gdb
------------------
  make debug
  gdb ./bin/im_the_exec
  (gdb) break gcd
  (gdb) run 1071 462
  (gdb) layout src
  (gdb) next
  (gdb) print a, b
  (gdb) bt

Makefile explained
------------------
A rule has the form:
  target: dependencies
      recipe

- target: the file to generate (example: program, file.o).
- dependencies: files needed to build the target (.c, .h, .o).
- recipe: shell commands (must start with TAB). Executed when the target
  is missing or dependencies are newer.

Variables in the Makefile:
- CC: compiler (default gcc, can override with make CC=clang).
- CFLAGS: compiler options (warnings, debug info, optimizations).
- CPPFLAGS: preprocessor flags (-I include paths).
- LDFLAGS, LDLIBS: linker flags and libraries.

Files:
- SRC: source files (.c).
- OBJ: object files (.o).
- TARGET: name of the final executable.

Extra tips
----------
- Use make -n to preview commands without running them.
- Add more source files to SRC, objects are generated automatically.
- Directories bin/ and build/ keep executables and object files separate.

