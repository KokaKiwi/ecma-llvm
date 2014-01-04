#ifndef ECMA_COMPILER_HELPER_TYPE_H_
#define ECMA_COMPILER_HELPER_TYPE_H_

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/TypeBuilder.h>

namespace llvm
{
    template<>
    struct TypeBuilder<bool, false>
    {
        static llvm::Type *get(llvm::LLVMContext &context)
        {
            return llvm::Type::getInt1Ty(context);
        }
    };
}

namespace ecma
{
    namespace compiler
    {
        namespace helper
        {
            template<typename T, bool XCompile = false>
            inline auto type(llvm::LLVMContext &context) -> decltype(llvm::TypeBuilder<T, XCompile>::get(context))
            {
                return llvm::TypeBuilder<T, XCompile>::get(context);
            }
        }
    }
}

#endif /* ECMA_COMPILER_HELPER_TYPE_H_ */
