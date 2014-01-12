#ifndef LLVMPP_ABSTRACTCLASS_H_
#define LLVMPP_ABSTRACTCLASS_H_

#include <llvm/IR/LLVMContext.h>
#include "llvmpp/Class.h"

namespace llvmpp
{
    class AbstractClass: public Class
    {
    public:
        inline AbstractClass(llvm::LLVMContext &context)
            : Class(context)
        {}

        inline virtual llvm::Value *add(llvm::IRBuilder<> &irBuilder, llvm::Value *a, llvm::Value *b) const
        {
            return nullptr;
        }

        inline virtual llvm::Value *sub(llvm::IRBuilder<> &irBuilder, llvm::Value *a, llvm::Value *b) const
        {
            return nullptr;
        }

        inline virtual llvm::Value *mul(llvm::IRBuilder<> &irBuilder, llvm::Value *a, llvm::Value *b) const
        {
            return nullptr;
        }

        inline virtual llvm::Value *div(llvm::IRBuilder<> &irBuilder, llvm::Value *a, llvm::Value *b) const
        {
            return nullptr;
        }

        inline virtual llvm::Value *mod(llvm::IRBuilder<> &irBuilder, llvm::Value *a, llvm::Value *b) const
        {
            return nullptr;
        }
    };
}

#endif /* LLVMPP_ABSTRACTCLASS_H_ */
