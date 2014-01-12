#ifndef LLVMPP_CLASS_H_
#define LLVMPP_CLASS_H_

#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>

namespace llvmpp
{
    class Class
    {
    public:
        inline Class(llvm::LLVMContext &context)
            : Context(context)
        {}

        virtual llvm::Value *add(llvm::IRBuilder<> &irBuilder, llvm::Value *a, llvm::Value *b) const = 0;
        virtual llvm::Value *sub(llvm::IRBuilder<> &irBuilder, llvm::Value *a, llvm::Value *b) const = 0;
        virtual llvm::Value *mul(llvm::IRBuilder<> &irBuilder, llvm::Value *a, llvm::Value *b) const = 0;
        virtual llvm::Value *div(llvm::IRBuilder<> &irBuilder, llvm::Value *a, llvm::Value *b) const = 0;
        virtual llvm::Value *mod(llvm::IRBuilder<> &irBuilder, llvm::Value *a, llvm::Value *b) const = 0;

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
