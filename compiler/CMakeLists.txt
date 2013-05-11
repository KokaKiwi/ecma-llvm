cmake_minimum_required(VERSION 2.8)

find_package(LLVM REQUIRED)
add_definitions(${LLVM_CPPFLAGS})
include_directories(${LLVM_INCLUDE_DIR})

file(GLOB_RECURSE EcmaCompiler_SOURCES *.cpp)

add_library(EcmaCompiler STATIC ${EcmaCompiler_SOURCES})
