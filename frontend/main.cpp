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

static bool runPhases(std::vector<frontend::Phase *> &phases)
{
    std::vector<std::unique_ptr<frontend::Unit>> units;

    for (auto phase: phases)
    {
        switch (phase->run(units))
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
    std::vector<frontend::Phase *> phases;

    registerPhases(phases);

    llvm::cl::ParseCommandLineOptions(argc, argv, nullptr);

    if (frontend::args::noColor)
    {
        utils::Messages::DisableColors();
    }

    bool result = runPhases(phases);

    for (auto phase: phases)
    {
        delete phase;
    }

    utils::Messages::Summary();

    return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
