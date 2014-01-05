#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <llvm/Support/CommandLine.h>
#include "ecma/frontend/args.h"
#include "ecma/frontend/unit.h"
#include "ecma/frontend/phase.h"
#include "ecma/frontend/phases.h"
#include "ecma/utils/messages.h"

using namespace ecma;

namespace
{
    #define ECMA_ARG(type, name, ...) type name(__VA_ARGS__);

    #include "ecma/frontend/args_list.h"

    #undef ECMA_ARG
}

static void registerPhases(std::vector<frontend::Phase *> &phases)
{
    // Input phase
    phases.push_back(new frontend::input::Input());

    // Parsing phase
    phases.push_back(new frontend::parse::Parse());

    // Compilation phase
    phases.push_back(new frontend::compile::Compile());

    // Output phase
    phases.push_back(new frontend::output::Output());
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

    #define ECMA_ARG(type, name, ...) args.name = &name;

    #include "ecma/frontend/args_list.h"

    #undef ECMA_ARG

    registerPhases(phases);

    llvm::cl::ParseCommandLineOptions(argc, argv, nullptr);

    if (*args.noColor)
    {
        utils::Messages::DisableColors();
    }

    bool result = runPhases(args, phases);

    for (auto phase: phases)
    {
        delete phase;
    }

    utils::Messages::Summary();

    return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
