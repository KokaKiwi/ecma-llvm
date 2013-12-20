#include <vector>
#include <string>
#include <iostream>
#include "ezOptionParser.hpp"
#include "ecma/frontend/args.h"

using namespace ecma;
using namespace ecma::frontend;

static std::string OVERVIEW = "ECMAScript 5 compliant compiler.";
static std::string SYNTAX = "ecmac [OPT] [FILE [FILE...]]";

Args::Args()
    : ez::ezOptionParser()
{
    this->overview = OVERVIEW;
    this->syntax = SYNTAX;

    // General args
    add("", false, 0, 0, "Show this help and exit.", "-h", "--help");
}

void Args::printUsage(std::ostream &stream)
{
    std::string usage;
    this->getUsage(usage);
    std::cout << usage;
}

bool Args::check()
{
    std::vector<std::string> badOptions;

    if (!this->gotRequired(badOptions))
    {
        for (auto opt: badOptions)
        {
            std::cerr << "Missing required option '" << opt << "'." << std::endl << std::endl;
        }

        this->printUsage(std::cerr);
        return false;
    }

    if (!this->gotExpected(badOptions))
    {
        for (auto opt: badOptions)
        {
            std::cerr << "Got unexpected number of arguments for option '" << opt << "'." << std::endl << std::endl;
        }

        this->printUsage(std::cerr);
        return false;
    }

    return true;
}
