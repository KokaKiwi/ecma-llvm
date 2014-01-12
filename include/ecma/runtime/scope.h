#ifndef ECMA_RUNTIME_SCOPE_H_
#define ECMA_RUNTIME_SCOPE_H_

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>

namespace ecma
{
    namespace runtime
    {
        class Scope
        {
        public:
            static llvm::Type *GetEnvType(llvm::LLVMContext &context);

        private:
        };
    }
}

#endif /* ECMA_RUNTIME_SCOPE_H_ */
