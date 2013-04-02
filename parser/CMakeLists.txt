cmake_minimum_required(VERSION 2.8)

find_package(Ragel REQUIRED)
find_package(Lemon REQUIRED)

ragel_generate(EcmaLexer lexer.cpp lex/lexer.rl)
lemon_generate(EcmaLParser "${CMAKE_CURRENT_BINARY_DIR}" ".cpp" parser/lemon-parser.lm)

set(EcmaParser_SOURCES
    lexer.cpp
    ${EcmaLParser_SOURCE}
    lex/lexeme.cpp
    parser/parser.cpp
    parser/exception.cpp
    source.cpp)

add_library(EcmaParser STATIC ${EcmaParser_SOURCES})
