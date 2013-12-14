#include <cstdlib>
#include <string>
#include <iostream>
#include "ecma/lex/lexer.h"
#include "ecma/lex/exception.h"
#include "ecma/parser/parser.h"
#include "ecma/parser/exception.h"
#include "ecma/utils/messages.h"

using namespace ecma;

#include "sample.cpp"
#define sample_js ___parser_sample_js
#define sample_js_len ___parser_sample_js_len

static std::string SOURCE = std::string((char *) sample_js, sample_js_len);

int main(int argc, char **argv)
{
    lex::Lexer lexer(SOURCE);
    parser::Parser parser;

    utils::Messages::SetSourceName("sample.js");
    utils::Messages::SetSource(SOURCE);

    try
    {
        parser.parse(lexer);
    }
    catch (parser::UnexpectedToken &e)
    {
        e.printMessage();
    }
    catch (lex::UnknownTokenException &e)
    {
        e.printMessage();
    }

    utils::Messages::Summary();

    return EXIT_SUCCESS;
}
