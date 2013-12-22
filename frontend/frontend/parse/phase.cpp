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

void Parse::init(Args &args)
{
    args.add("", false, 0, 0, "Run the parse phase.", "-P");
}

Phase::Result Parse::run(Args &args, std::vector<std::unique_ptr<Unit>> &units)
{
    bool success = true;

    for (auto it = units.begin(); it != units.end(); ++it)
    {
        try
        {
            auto module = (*it)->source().parse();
            (*it)->module(module);
        }
        catch (lex::UnknownTokenException &e)
        {
            e.printMessage();
            success = false;
        }
    }

    if (utils::Messages::HasErrors())
    {
        return Phase::Result::ERROR;
    }

    return args.isSet("-P") ? Phase::Result::STOP : Phase::Result::CONTINUE;
}
