#include <cstdlib>
#include <string>
#include <iostream>
#include "ecma/lex/lexer.h"
#include "ecma/lex/token.h"

using namespace ecma;

#include "sample.cpp"
#define sample_js ___parser_sample_js
#define sample_js_len ___parser_sample_js_len

static std::string SOURCE = std::string((char *) sample_js, sample_js_len);

int main(int argc, char **argv)
{
    lex::Lexer lexer(SOURCE);
    lex::Token *token = nullptr;

    do
    {
        delete token;

        token = lexer.consume();
        std::cout << *token << std::endl;
    }
    while (token->type() != lex::Token::Type::END);
    delete token;

    return EXIT_SUCCESS;
}
