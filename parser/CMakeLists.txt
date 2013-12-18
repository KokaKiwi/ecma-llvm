cmake_minimum_required(VERSION 2.8)

# Paths
set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Build lexer
find_package(Ragel REQUIRED)
set(RAGEL_FLAGS "-F1")

ragel_generate(ecma_lexer_gen lexer.cpp lex/lexer.rl)

# Build parser
find_package(Lemon REQUIRED)
include_directories(${PROJECT_BUILD_DIR})

lemon_generate(ecma_parser_gen "${PROJECT_BUILD_DIR}" ".cpp" parser/lemon-parser.lm)

# Build library
set(ecma_parser_SOURCES
    lexer.cpp
    lex/token.cpp
    lex/exception.cpp

    ${ecma_parser_gen_SOURCE}
    parser/parser.cpp
    parser/exception.cpp

    ast/expr/literal/regexp.cpp

    toolchain/source.cpp
)

add_library(ecma_parser STATIC ${ecma_parser_SOURCES})

# Variables
set(ecma_parser_INCLUDE_DIRS
    ${PROJECT_BUILD_DIR}
PARENT_SCOPE)

set(ecma_parser_LIBRARIES
    ecma_parser
PARENT_SCOPE)
