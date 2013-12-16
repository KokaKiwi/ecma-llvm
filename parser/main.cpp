#include <cstdlib>
#include <string>
#include <memory>
#include <iostream>
#include "ecma/lex/exception.h"
#include "ecma/parser/exception.h"
#include "ecma/toolchain/source.h"
#include "ecma/utils/messages.h"
#include "ecma/ast/ast.h"

using namespace ecma;

static bool is_debug()
{
    const char *debug_env = getenv("DEBUG");

    if (debug_env)
    {
        std::string debug(debug_env);

        return debug == "1";
    }

    return false;
}

int main(int argc, char **argv)
{
    std::unique_ptr<toolchain::Source> source;
    ast::Module *module = nullptr;

    if (argc == 1)
    {
        source.reset(toolchain::Source::fromStream(std::cin, "stdin"));
    }
    else if (argc > 1)
    {
        source.reset(toolchain::Source::fromFile(argv[1]));
    }

    if (source)
    {
        try
        {
            module = source->parse(is_debug());
        }
        catch (parser::UnexpectedToken &e)
        {
            e.printMessage();
        }
        catch (lex::UnknownTokenException &e)
        {
            e.printMessage();
        }
    }

    utils::Messages::Summary();

    delete module;
    return EXIT_SUCCESS;
}
