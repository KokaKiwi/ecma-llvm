#include <cstdlib>
#include <cstdio>
#include <memory>
#include <iostream>
#include "ecma/parser/parser.h"

using namespace ecma::parser;

Parser::Parser(lex::Lexer &lexer)
    : m_lexer(lexer)
    , m_debug(false)
    , m_program(nullptr)
{
    m_yyp = EcmaParseAlloc(&malloc);
}

Parser::~Parser()
{
    EcmaParseFree(m_yyp, &free);
}

void Parser::exec()
{
    bool parsing = true;

    if (debug())
    {
        EcmaParseTrace(stderr, "[EcmaParser] ");
    }
    else
    {
        EcmaParseTrace(NULL, NULL);
    }

    while (parsing)
    {
        lexeme(m_lexer.consume());

        if (lexeme()->type() != lex::Lexeme::Type::Spaces && lexeme()->type() != lex::Lexeme::Type::Newline)
        {
            EcmaParse(m_yyp, static_cast<int>(lexeme()->type()), lexeme(), this);

            if (lexeme()->type() == lex::Lexeme::Type::End)
            {
                parsing = false;
                delete takeLexeme();
            }

            takeLexeme();
        }
    }
}
