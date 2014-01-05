#include <vector>
#include <string>
#include <iostream>
#include "ecma/frontend/args.h"

using namespace ecma;
using namespace ecma::frontend;

bool Args::hasCompilerFlag(const std::string &search_flag)
{
    for (const std::string &flag: *compilerFlags)
    {
        if (flag == search_flag)
        {
            return true;
        }
    }

    return false;
}
