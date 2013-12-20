#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include "ecma/frontend/args.h"
#include "ecma/toolchain/source.h"

using namespace ecma;

toolchain::Source *readSource(const std::string &filename = "-")
{
    if (filename == "-")
    {
        return toolchain::Source::fromStream(std::cin, "stdin");
    }

    return toolchain::Source::fromFile(filename);
}

int main(int argc, const char **argv)
{
    frontend::Args args;
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

    std::vector<std::unique_ptr<toolchain::Source>> sources;
    if (args.lastArgs.size() == 0)
    {
        sources.push_back(std::unique_ptr<toolchain::Source>(readSource()));
    }
    else
    {
        for (auto it: args.lastArgs)
        {
            sources.push_back(std::unique_ptr<toolchain::Source>(readSource(*it)));
        }
    }

    return EXIT_SUCCESS;
}
