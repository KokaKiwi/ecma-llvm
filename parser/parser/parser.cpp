#include <cstdlib>
#include <cstdio>
#include <memory>
#include <vector>
#include <algorithm>
#include "ecma/lex/lexer.h"
#include "ecma/lex/token.h"
#include "ecma/parser/parser.h"

using namespace ecma;
using namespace ecma::parser;

#define ECMA_TOKEN(name) lex::Token::Type::name

Parser::Parser()
    : m_debug(false)
    , m_module(nullptr)
{
    m_yyp = ecma_parseAlloc(malloc);
}

Parser::~Parser()
{
    ecma_parseFree(m_yyp, free);
}

void Parser::parse(lex::Lexer &lexer)
{
    std::vector<lex::Token::Type> ignore {
        ECMA_TOKEN(SPACES),
        ECMA_TOKEN(NEWLINE),
        ECMA_TOKEN(COMMENT),
    };

    #ifndef NDEBUG
    if (m_debug)
    {
        ecma_parseTrace(stderr, (char *)"[ecma-llvm] ");
    }
    #endif /* NDEBUG */

    while (true)
    {
        lex::Token *token = lexer.consume();

        if (std::find(ignore.begin(), ignore.end(), token->type()) == ignore.end())
        {
            ecma_parse(m_yyp, static_cast<int>(token->type()), token, this);

            if (token->type() == ECMA_TOKEN(END))
            {
                break;
            }
        }
        else
        {
            delete token;
        }
    }
}
