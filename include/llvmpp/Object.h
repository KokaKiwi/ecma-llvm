#ifndef LLVMPP_OBJECT_H_
#define LLVMPP_OBJECT_H_

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>
#include "llvmpp/Class.h"

namespace llvmpp
{
    class Object
    {
    public:
        inline Object(const Class *cl, llvm::Value *value)
            : Cl(cl)
            , Value(value)
        {}

        inline Object add(llvm::IRBuilder<> &irBuilder, const Object &other)
        {
            return Cl->add(irBuilder, *this, other);
        }

        inline Object sub(llvm::IRBuilder<> &irBuilder, const Object &other)
        {
            return Cl->sub(irBuilder, *this, other);
        }

        inline Object mul(llvm::IRBuilder<> &irBuilder, const Object &other)
        {
            return Cl->mul(irBuilder, *this, other);
        }

        inline Object div(llvm::IRBuilder<> &irBuilder, const Object &other)
        {
            return Cl->div(irBuilder, *this, other);
        }

        inline Object mod(llvm::IRBuilder<> &irBuilder, const Object &other)
        {
            return Cl->mod(irBuilder, *this, other);
        }

    protected:
        const Class *Cl;
        llvm::Value *Value;
    };
}

#endif /* LLVMPP_OBJECT_H_ */
