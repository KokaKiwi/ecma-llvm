ecma-llvm
=========

ECMAScript-to-LLVM compiler (more "Javascript").

Status: WIP.
Build status: ![Build status](https://travis-ci.org/KokaKiwi/ecma-llvm.png?branch=reboot)

How to build
------------

~~~sh
    mkdir build
    cd build
    cmake ..
    make
~~~

Build files:
- bin/ecmap: small dev parser executable. It just parse input and print out the AST.
- lib/*: Core libraries

Requirements
============
- CMake (Building tools): [http://www.cmake.org](http://www.cmake.org)
- LLVM libraries (LLVM IR code generation): [http://llvm.org](http://llvm.org)
- Ragel (Lexer generating): [http://www.complang.org/ragel/](http://www.complang.org/ragel/)
- Lemon (Parsing generating): [http://www.hwaci.com/sw/lemon/](http://www.hwaci.com/sw/lemon/)

Some links
==========
- Castel language (by the guy who introduced me to LLVM :D): [http://castel.github.io](http://castel.github.io)
