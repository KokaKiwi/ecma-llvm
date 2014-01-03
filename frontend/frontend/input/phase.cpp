#include <vector>
#include <memory>
#include <iostream>
#include "ecma/frontend/args.h"
#include "ecma/frontend/unit.h"
#include "ecma/frontend/input/phase.h"
#include "ecma/parser/toolchain/source.h"

using namespace ecma;
using namespace ecma::frontend;
using namespace ecma::frontend::input;

static parser::toolchain::Source *readSource(const std::string &filename = "-")
{
    if (filename == "-")
    {
        return parser::toolchain::Source::fromStream(std::cin, "-");
    }
    else
    {
        return parser::toolchain::Source::fromFile(filename);
    }
}

void Input::init(Args &args)
{
}

Phase::Result Input::run(Args &args, std::vector<std::unique_ptr<Unit>> &units)
{
    if (args.lastArgs.size() == 0)
    {
        auto unit = new frontend::Unit(readSource());
        units.push_back(std::unique_ptr<frontend::Unit>(unit));
    }
    else
    {
        for (auto it: args.lastArgs)
        {
            auto unit = new frontend::Unit(readSource(*it));
            units.push_back(std::unique_ptr<frontend::Unit>(unit));
        }
    }

    return Phase::Result::CONTINUE;
}
