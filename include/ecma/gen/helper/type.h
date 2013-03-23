#ifndef ECMA_GEN_HELPER_TYPE_H_
#define ECMA_GEN_HELPER_TYPE_H_

#include <llvm/TypeBuilder.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Type.h>

namespace ecma
{
    namespace gen
    {
        namespace helper
        {
            template<typename T>
            inline auto type(llvm::LLVMContext &context) -> decltype(llvm::TypeBuilder<T, false>::get(context))
            {
                return llvm::TypeBuilder<T, false>::get(context);
            }
        }
    }
}

#endif /* ECMA_GEN_HELPER_TYPE_H_ */
