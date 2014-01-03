ecma-llvm
=========

ECMAScript-to-LLVM compiler (more "Javascript").

Status: WIP.

Build status: [![Build status](https://travis-ci.org/KokaKiwi/ecma-llvm.png?branch=reboot)](https://travis-ci.org/KokaKiwi/ecma-llvm)

How to build
------------

~~~sh
    mkdir build
    cd build
    cmake ..
    make
~~~

Build files:
- bin/ecmac: Main frontend executable.
- lib/*: Core libraries

Requirements
============
- CMake (Building tools): [http://www.cmake.org](http://www.cmake.org)
- LLVM libraries (LLVM IR code generation) (version needed: 3.3): [http://llvm.org](http://llvm.org)
- Ragel (Lexer generating): [http://www.complang.org/ragel/](http://www.complang.org/ragel/)
- Lemon (Parsing generating): [http://www.hwaci.com/sw/lemon/](http://www.hwaci.com/sw/lemon/)

Contributing
============

### I want to add a feature / fix a bug ###
- Fork the repository.
- Create a branch named by the feature / the bug fix you want to develop.
- Commit and push.
- Create a Pull Request.
- Wait. I'm not at full time on this project, so you must wait before I see your PR.

### I want to send you a bug I discovered / a feature I want to be added ###
- Create an issue here: [https://github.com/KokaKiwi/ecma-llvm/issues/new](https://github.com/KokaKiwi/ecma-llvm/issues/new)
- Wait an answer (from me, or another guy).

Some links
==========
- Castel language (by the guy who introduced me to LLVM :D): [http://castel.github.io](http://castel.github.io)

License
=======
ecma-llvm is licensed under the MIT license - see the `LICENSE` file for details.
