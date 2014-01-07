#ifndef ECMA_FRONTEND_ARGS_H_
#define ECMA_FRONTEND_ARGS_H_

#include <string>
#include <iostream>
#include <llvm/Support/CommandLine.h>

namespace ecma
{
    namespace frontend
    {
        namespace args
        {
            #define ECMA_ARG(type, name, ...) extern type name;

            #include "ecma/frontend/args_list.h"

            #undef ECMA_ARG

            bool hasCompilerFlag(const std::string &search_flag);
        }
    }
}

#endif /* ECMA_FRONTEND_ARGS_H_ */
