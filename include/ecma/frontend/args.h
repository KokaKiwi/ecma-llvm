#ifndef ECMA_FRONTEND_ARGS_H_
#define ECMA_FRONTEND_ARGS_H_

#include <string>
#include <iostream>
#include <llvm/Support/CommandLine.h>

namespace ecma
{
    namespace frontend
    {
        class Args
        {
        public:
            bool hasCompilerFlag(const std::string &search_flag);

        public:
            #define ECMA_ARG(type, name, ...) type *name;

            #include "ecma/frontend/args_list.h"

            #undef ECMA_ARG
        };
    }
}

#endif /* ECMA_FRONTEND_ARGS_H_ */
