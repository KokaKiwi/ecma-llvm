#ifndef LLVMPP_CLASS_H_
#define LLVMPP_CLASS_H_

#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>

namespace llvmpp
{
    class Object;

    class Class
    {
    public:
        inline Class(llvm::LLVMContext &context)
            : Context(context)
        {}

        virtual Object add(const Object &a, const Object &b) const = 0;
        virtual Object sub(const Object &a, const Object &b) const = 0;
        virtual Object mul(const Object &a, const Object &b) const = 0;
        virtual Object div(const Object &a, const Object &b) const = 0;
        virtual Object mod(const Object &a, const Object &b) const = 0;

        inline llvm::Type *GetType() const
        {
            return Type;
        }

        inline llvm::PointerType *GetPointerType(unsigned int address = 0) const
        {
            return llvm::PointerType::get(GetType(), address);
        }

    protected:
        virtual llvm::Type *ConstructType() const = 0;

    protected:
        llvm::LLVMContext &Context;
        llvm::Type *Type;
    };
}

#endif /* LLVMPP_CLASS_H_ */
