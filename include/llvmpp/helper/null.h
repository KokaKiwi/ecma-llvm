#ifndef LLVMPP_COMPILER_HELPER_NULL_H_
#define LLVMPP_COMPILER_HELPER_NULL_H_

#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Value.h>

#include "llvmpp/helper/type.h"

namespace llvmpp
{
    namespace helper
    {
        inline llvm::ConstantPointerNull *null(llvm::PointerType *type)
        {
            return llvm::ConstantPointerNull::get(type);
        }

        template <typename T>
        inline llvm::ConstantPointerNull *null(llvm::LLVMContext &context)
        {
            return helper::null(helper::type<T>(context));
        }
    }
}

#endif /* LLVMPP_COMPILER_HELPER_NULL_H_ */
