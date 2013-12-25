#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include "ecma/frontend/args.h"
#include "ecma/frontend/unit.h"
#include "ecma/frontend/phase.h"
#include "ecma/frontend/input/phase.h"
#include "ecma/frontend/parse/phase.h"
#include "ecma/toolchain/source.h"
#include "ecma/utils/messages.h"

using namespace ecma;

static void registerPhases(std::vector<frontend::Phase *> &phases)
{
    phases.push_back(new frontend::input::Input());
    phases.push_back(new frontend::parse::Parse());
}

static void initPhases(frontend::Args &args, std::vector<frontend::Phase *> &phases)
{
    for (auto phase: phases)
    {
        phase->init(args);
    }
}

static bool runPhases(frontend::Args &args, std::vector<frontend::Phase *> &phases)
{
    std::vector<std::unique_ptr<frontend::Unit>> units;

    for (auto phase: phases)
    {
        switch (phase->run(args, units))
        {
            case frontend::Phase::Result::STOP:
                return true;
            case frontend::Phase::Result::ERROR:
                return false;
            default:
                break;
        }
    }

    return true;
}

int main(int argc, const char **argv)
{
    frontend::Args args;
    std::vector<frontend::Phase *> phases;

    registerPhases(phases);
    initPhases(args, phases);

    args.parse(argc, argv);
    if (!args.check())
    {
        return EXIT_FAILURE;
    }

    if (args.isSet("-h"))
    {
        args.printUsage();
        return EXIT_SUCCESS;
    }

    bool result = runPhases(args, phases);

    for (auto phase: phases)
    {
        delete phase;
    }

    utils::Messages::Summary();

    return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
