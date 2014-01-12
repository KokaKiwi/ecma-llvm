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

        inline virtual Object add(const Object &a, const Object &b) const
        {
            return empty();
        }

        inline virtual Object sub(const Object &a, const Object &b) const
        {
            return empty();
        }

        inline virtual Object mul(const Object &a, const Object &b) const
        {
            return empty();
        }

        inline virtual Object div(const Object &a, const Object &b) const
        {
            return empty();
        }

        inline virtual Object mod(const Object &a, const Object &b) const
        {
            return empty();
        }
    };
}

#endif /* LLVMPP_ABSTRACTCLASS_H_ */
