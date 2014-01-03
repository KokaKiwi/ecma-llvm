#ifndef ECMA_FRONTEND_OUTPUT_PHASE_H_
#define ECMA_FRONTEND_OUTPUT_PHASE_H_

#include <vector>
#include <memory>
#include <llvm/Target/TargetMachine.h>
#include "ecma/frontend/args.h"
#include "ecma/frontend/unit.h"
#include "ecma/frontend/phase.h"

#define EXT_OBJECT      ".jso"
#define EXT_ASM         ".s"
#define EXT_LLVM        ".ll"
#define EXT_LLVM_BC     ".bc"

namespace ecma
{
    namespace frontend
    {
        namespace output
        {
            class Output: public Phase
            {
            public:
                void init(Args &args);
                Phase::Result run(Args &args, std::vector<std::unique_ptr<Unit>> &units);

            private:
                bool outputModule(const llvm::Module *module, llvm::formatted_raw_ostream &out, bool asmOutput, bool llvmOutput);

            private:
                const llvm::Target *target;
                std::unique_ptr<llvm::TargetMachine> targetMachine;
            };
        }
    }
}

#endif /* ECMA_FRONTEND_OUTPUT_PHASE_H_ */
