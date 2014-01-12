#ifndef LLVMPP_OBJECT_H_
#define LLVMPP_OBJECT_H_

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

        inline Object operator +(const Object &b) const
        {
            return Cl->add(*this, b);
        }

        inline Object operator -(const Object &b) const
        {
            return Cl->sub(*this, b);
        }

        inline Object operator *(const Object &b) const
        {
            return Cl->mul(*this, b);
        }

        inline Object operator /(const Object &b) const
        {
            return Cl->div(*this, b);
        }

        inline Object operator %(const Object &b) const
        {
            return Cl->mod(*this, b);
        }

    protected:
        const Class *Cl;
        llvm::Value *Value;
    };
}

#endif /* LLVMPP_OBJECT_H_ */
