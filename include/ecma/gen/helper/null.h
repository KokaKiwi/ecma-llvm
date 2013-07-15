#ifndef ECMA_GEN_HELPER_NULL_H_
#define ECMA_GEN_HELPER_NULL_H_

#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Value.h>

#include "ecma/gen/helper/type.h"

namespace ecma
{
    namespace gen
    {
        namespace helper
        {
            inline llvm::ConstantPointerNull *null(llvm::PointerType *type)
            {
                return llvm::ConstantPointerNull::get( type );
            }

            template <typename T>
            inline llvm::ConstantPointerNull *null(llvm::LLVMContext & context )
            {
                return gen::helper::null(gen::helper::type<T>(context));
            }
        }
    }
}

#endif /* ECMA_GEN_HELPER_NULL_H_ */
