cmake_minimum_required(VERSION 2.8)

find_package(LLVM REQUIRED)
add_definitions(${LLVM_CPPFLAGS})
include_directories(${LLVM_INCLUDE_DIR})

# set(EcmaCompiler_SOURCES
#     toolchain/compiler.cpp
#     gen/module.cpp
#     gen/code.cpp
#     gen/scope.cpp
#     gen/stmt/expression.cpp
#     gen/stmt/block.cpp
#     gen/stmt/decl/variables.cpp
#     gen/expr/assign.cpp
#     gen/expr/identifier.cpp
#     gen/expr/literal/integer.cpp
# )
file(GLOB_RECURSE EcmaCompiler_SOURCES *.cpp)

add_library(EcmaCompiler STATIC ${EcmaCompiler_SOURCES})
