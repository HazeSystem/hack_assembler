# hack_assembler

Hack assembler for the Nand2tetris course. http://www.nand2tetris.org/

It's now a complete assembler! Currently can only handle the command line argument being the bare file name. Improving that and other small improvements coming maybe.

Uses CMake. Windows and Linux builds tested and confirmed working, OS X should work but I'm not able to test it myself.

# Dependencies

- CMake (for building)
- boost

# Building

```
mkdir build
cd build
cmake ../
make
```
