#include <vector>
#include <memory>
#include <iostream>
#include "ecma/frontend/args.h"
#include "ecma/frontend/unit.h"
#include "ecma/frontend/parse/phase.h"
#include "ecma/lex/exception.h"
#include "ecma/utils/messages.h"

using namespace ecma;
using namespace ecma::frontend;
using namespace ecma::frontend::parse;

Phase::Result Parse::run(std::vector<std::unique_ptr<Unit>> &units)
{
    for (auto it = units.begin(); it != units.end(); ++it)
    {
        try
        {
            bool debug = args::hasCompilerFlag("parse-debug") || args::hasCompilerFlag("debug");
            auto module = (*it)->source().parse(debug);
            (*it)->ast_module(module);
        }
        catch (lex::UnknownTokenException &e)
        {
            e.printMessage();
        }
    }

    if (utils::Messages::HasErrors())
    {
        return Phase::Result::ERROR;
    }

    return (args::parseOnly) ? Phase::Result::STOP : Phase::Result::CONTINUE;
}
