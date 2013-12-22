#ifndef ECMA_FRONTEND_PHASE_H_
#define ECMA_FRONTEND_PHASE_H_

#include <vector>
#include <memory>
#include "ecma/frontend/unit.h"

namespace ecma
{
    namespace frontend
    {
        class Phase
        {
        public:
            enum class Result
            {
                CONTINUE,
                STOP,
                ERROR,
            };

            inline Phase() {}
            inline virtual ~Phase() {}

            virtual void init(Args &args) = 0;
            virtual Result run(Args &args, std::vector<std::unique_ptr<Unit>> &units) = 0;
        };
    }
}

#endif /* ECMA_FRONTEND_PHASE_H_ */
