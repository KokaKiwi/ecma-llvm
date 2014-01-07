#include <vector>
#include <string>
#include <iostream>
#include "ecma/frontend/args.h"

namespace ecma
{
    namespace frontend
    {
        namespace args
        {
            #define ECMA_ARG(type, name, ...) type name(__VA_ARGS__);

            #include "ecma/frontend/args_list.h"

            #undef ECMA_ARG

            bool hasCompilerFlag(const std::string &search_flag)
            {
                for (const std::string &flag: args::compilerFlags)
                {
                    if (flag == search_flag)
                    {
                        return true;
                    }
                }

                return false;
            }
        }
    }
}
