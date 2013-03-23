cmake_minimum_required(VERSION 2.8)

find_package(LLVM REQUIRED)
add_definitions(${LLVM_CPPFLAGS})
link_libraries(${LLVM_LIBRARIES_ALL} ${LLVM_LDFLAGS})
link_directories(${LLVM_LIB_DIR})
include_directories(${LLVM_INCLUDE_DIR})

set(EcmaCompiler_SOURCES
    toolchain/compiler.cpp
    gen/module_builder.cpp
    gen/code_builder.cpp
    gen/scope.cpp
    gen/stmt/block.cpp
    gen/stmt/expression.cpp
    gen/stmt/return.cpp
    gen/stmt/decl/variables.cpp
    gen/expr/assignment.cpp
    gen/expr/binary.cpp
    gen/expr/unary.cpp
    gen/expr/literal/function_call.cpp
    gen/expr/literal/identifier.cpp
    gen/expr/literal/number.cpp
    gen/expr/literal/string.cpp)

add_library(EcmaCompiler STATIC ${EcmaCompiler_SOURCES})
