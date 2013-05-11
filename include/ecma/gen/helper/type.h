#ifndef ECMA_GEN_HELPER_TYPE_H_
#define ECMA_GEN_HELPER_TYPE_H_

#include <llvm/TypeBuilder.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Type.h>
#include "ecma/runtime/object.h"
#include "ecma/runtime/type/integer.h"
#include "ecma/runtime/type/string.h"
#include "ecma/runtime/type/boolean.h"
#include "ecma/runtime/type/null.h"
#include "ecma/runtime/type/undefined.h"
#include "ecma/runtime/type/function.h"

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

    template<bool XCompile>
    struct TypeBuilder<ecma::runtime::Object, XCompile>
    {
        static llvm::StructType *get(llvm::LLVMContext &context)
        {
            llvm::Module tmp("", context);
            return tmp.getTypeByName("Object");
        }
    };

    template<bool XCompile>
    struct TypeBuilder<ecma::runtime::type::Integer, XCompile>
        : public TypeBuilder<ecma::runtime::Object, XCompile>
    {};

    template<bool XCompile>
    struct TypeBuilder<ecma::runtime::type::String, XCompile>
        : public TypeBuilder<ecma::runtime::Object, XCompile>
    {};

    template<bool XCompile>
    struct TypeBuilder<ecma::runtime::type::Boolean, XCompile>
        : public TypeBuilder<ecma::runtime::Object, XCompile>
    {};

    template<bool XCompile>
    struct TypeBuilder<ecma::runtime::type::Null, XCompile>
        : public TypeBuilder<ecma::runtime::Object, XCompile>
    {};

    template<bool XCompile>
    struct TypeBuilder<ecma::runtime::type::Function, XCompile>
        : public TypeBuilder<ecma::runtime::Object, XCompile>
    {};

    template<bool XCompile>
    struct TypeBuilder<ecma::runtime::type::Undefined, XCompile>
        : public TypeBuilder<ecma::runtime::Object, XCompile>
    {};
}

namespace ecma
{
    namespace gen
    {
        namespace helper
        {
            template<typename T>
            inline auto type(llvm::LLVMContext &context) -> decltype(llvm::TypeBuilder<T, false>::get(context))
            {
                return llvm::TypeBuilder<T, false>::get(context);
            }
        }
    }
}

#endif /* ECMA_GEN_HELPER_TYPE_H_ */
