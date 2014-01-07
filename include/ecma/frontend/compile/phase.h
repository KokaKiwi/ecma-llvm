#ifndef ECMA_FRONTEND_COMPILE_PHASE_H_
#define ECMA_FRONTEND_COMPILE_PHASE_H_

#include <vector>
#include <memory>
#include "ecma/frontend/unit.h"
#include "ecma/frontend/phase.h"

#if defined(WIN32) || defined(_WIN32)
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

namespace ecma
{
    namespace frontend
    {
        namespace compile
        {
            class Compile: public Phase
            {
            public:
                Phase::Result run(std::vector<std::unique_ptr<Unit>> &units);
            };
        }
    }
}

#endif /* ECMA_FRONTEND_COMPILE_PHASE_H_ */
