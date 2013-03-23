cmake_minimum_required(VERSION 2.8)

add_custom_command(OUTPUT
    lexer.cpp
    COMMAND ragel -C -o lexer.cpp "${CMAKE_CURRENT_SOURCE_DIR}/lex/lexer.rl"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lex/lexer.rl")

add_custom_command(OUTPUT
    lemon-parser.cpp
    COMMAND lemon "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.lm"
    COMMAND rm "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.out"
    COMMAND mv "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.h" "${CMAKE_CURRENT_BINARY_DIR}/lemon-parser.h"
    COMMAND mv "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.c" "${CMAKE_CURRENT_BINARY_DIR}/lemon-parser.cpp"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.lm")

set(EcmaParser_SOURCES
    lexer.cpp
    lemon-parser.cpp
    lex/lexeme.cpp
    parser/parser.cpp
    parser/exception.cpp
    source.cpp)

add_library(EcmaParser STATIC ${EcmaParser_SOURCES})
