#include <vector>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include "ecma/runtime/scope.h"
#include "ecma/runtime/types/env.h"

using namespace ecma;
using namespace ecma::runtime;


llvm::Type *Scope::GetEnvType(llvm::LLVMContext &context)
{
    types::Env cl(context);

    return cl.GetType();
}
