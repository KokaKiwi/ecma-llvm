#include <cstdlib>
#include <iostream>
#include "ecma/frontend/args.h"

using namespace ecma;

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

    if (args.lastArgs.size() == 0)
    {
        // Read from stdin.
    }
    else
    {
        // Read files.
    }

    return EXIT_SUCCESS;
}
