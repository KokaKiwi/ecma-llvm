#ifndef ECMA_FRONTEND_PARSE_PHASE_H_
#define ECMA_FRONTEND_PARSE_PHASE_H_

#include <vector>
#include <memory>
#include "ecma/frontend/args.h"
#include "ecma/frontend/unit.h"
#include "ecma/frontend/phase.h"

namespace ecma
{
    namespace frontend
    {
        namespace parse
        {
            class Parse: public Phase
            {
            public:
                void init(Args &args);
                Phase::Result run(Args &args, std::vector<std::unique_ptr<Unit>> &units);
            };
        }
    }
}

#endif /* ECMA_FRONTEND_PARSE_PHASE_H_ */