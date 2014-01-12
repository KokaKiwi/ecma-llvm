#include <llvm/IR/LLVMContext.h>
#include <llvm/Analysis/Verifier.h>
#include "ecma/compiler/compiler.h"
#include "ecma/compiler/module.h"

using namespace ecma;
using namespace ecma::compiler;

llvm::Module *Compiler::compile(llvm::LLVMContext &context)
{
    llvm::Module *module = new llvm::Module(name(), context);

    Module(module).compile(context, this->module(), name());

    return module;
}
