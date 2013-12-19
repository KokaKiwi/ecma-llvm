#ifndef ECMA_FRONTEND_ARGS_H_
#define ECMA_FRONTEND_ARGS_H_

#include <iostream>
#include "ezOptionParser.hpp"

namespace ecma
{
    namespace frontend
    {
        class Args: public ez::ezOptionParser
        {
        public:
            Args();

            void printUsage(std::ostream &stream = std::cout);
            bool check();
        };
    }
}

#endif /* ECMA_FRONTEND_ARGS_H_ */
