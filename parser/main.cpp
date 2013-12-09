#include <cstdlib>
#include <string>
#include <iostream>
#include "ecma/lex/lexer.h"
#include "ecma/lex/token.h"

using namespace ecma;

static std::string SOURCE = "\n\
     \n\
";

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
