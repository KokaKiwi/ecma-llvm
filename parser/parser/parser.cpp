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
{
    m_yyp = ecma_parseAlloc(malloc);
}

Parser::~Parser()
{
    ecma_parseFree(m_yyp, free);
}

void Parser::parse(lex::Lexer &lexer)
{
    std::unique_ptr<lex::Token> token;
    std::vector<lex::Token::Type> ignore {
        ECMA_TOKEN(SPACES),
        ECMA_TOKEN(NEWLINE),
        ECMA_TOKEN(COMMENT),
    };

    while (true)
    {
        token.reset(lexer.consume());

        if (std::find(ignore.begin(), ignore.end(), token->type()) == ignore.end())
        {
            ecma_parse(m_yyp, static_cast<int>(token->type()), token.get(), this);

            if (token->type() == ECMA_TOKEN(END))
            {
                break;
            }
        }
    }
}
