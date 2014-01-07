#ifndef ECMA_FRONTEND_INPUT_PHASE_H_
#define ECMA_FRONTEND_INPUT_PHASE_H_

#include <vector>
#include <memory>
#include "ecma/frontend/unit.h"
#include "ecma/frontend/phase.h"

namespace ecma
{
    namespace frontend
    {
        namespace input
        {
            class Input: public Phase
            {
            public:
                Phase::Result run(std::vector<std::unique_ptr<Unit>> &units);
            };
        }
    }
}

#endif /* ECMA_FRONTEND_INPUT_PHASE_H_ */
