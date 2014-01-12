#ifndef ECMA_RUNTIME_TYPES_ENV_ENTRY_H_
#define ECMA_RUNTIME_TYPES_ENV_ENTRY_H_

#include <llvm/IR/Type.h>
#include "llvmpp/AbstractClass.h"

namespace ecma
{
    namespace runtime
    {
        namespace types
        {
            class EnvEntry: public llvmpp::AbstractClass
            {
            public:
                inline EnvEntry(llvm::LLVMContext &context)
                    : AbstractClass(context)
                {
                    Type = ConstructType();
                }

            protected:
                llvm::Type *ConstructType() const;
            };
        }
    }
}

#endif /* ECMA_RUNTIME_TYPES_ENV_ENTRY_H_ */
