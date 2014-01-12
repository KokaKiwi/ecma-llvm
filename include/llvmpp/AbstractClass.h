#ifndef LLVMPP_ABSTRACTCLASS_H_
#define LLVMPP_ABSTRACTCLASS_H_

#include <llvm/IR/LLVMContext.h>
#include "llvmpp/Class.h"
#include "llvmpp/Object.h"

namespace llvmpp
{
    class AbstractClass: public Class
    {
    public:
        inline AbstractClass(llvm::LLVMContext &context)
            : Class(context)
        {}

        inline Object empty() const
        {
            return Object(this, nullptr);
        }

        inline virtual Object add(llvm::IRBuilder<> &irBuilder, const Object &a, const Object &b) const
        {
            return empty();
        }

        inline virtual Object sub(llvm::IRBuilder<> &irBuilder, const Object &a, const Object &b) const
        {
            return empty();
        }

        inline virtual Object mul(llvm::IRBuilder<> &irBuilder, const Object &a, const Object &b) const
        {
            return empty();
        }

        inline virtual Object div(llvm::IRBuilder<> &irBuilder, const Object &a, const Object &b) const
        {
            return empty();
        }

        inline virtual Object mod(llvm::IRBuilder<> &irBuilder, const Object &a, const Object &b) const
        {
            return empty();
        }
    };
}

#endif /* LLVMPP_ABSTRACTCLASS_H_ */
