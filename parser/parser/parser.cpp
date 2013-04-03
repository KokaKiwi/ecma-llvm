#include <cstdlib>
#include <cstdio>
#include <memory>
#include "ecma/parser/parser.h"
#include "ecma/parser/exception.h"

using namespace ecma::parser;

Parser::Parser(lex::Lexer &lexer): m_lexer(lexer), m_error(false), m_program(nullptr)
{
    m_yyp = EcmaParseAlloc(&malloc);
    // EcmaParseTrace(stderr, "[EcmaParser] ");
}

Parser::~Parser()
{
    EcmaParseFree(m_yyp, &free);
}

void Parser::exec()
{
    std::unique_ptr<lex::Lexeme> lexeme;
    bool parsing = true;

    while (parsing && !error())
    {
        lexeme.reset(m_lexer.consume());

        if (lexeme->type() != lex::Lexeme::Type::Spaces && lexeme->type() != lex::Lexeme::Type::Newline)
        {
            EcmaParse(m_yyp, static_cast<int>(lexeme->type()), lexeme.get(), this);

            if (lexeme->type() == lex::Lexeme::Type::End)
            {
                parsing = false;
            }

            if (!error())
            {
                delete lexeme.release();
            }
        }
    }

    if (error())
    {
        throw Exception("Unexpected token", *lexeme, errors());
    }
}
