#include <llvm/IR/LLVMContext.h>
#include <llvm/Analysis/Verifier.h>
#include "ecma/compiler/compiler.h"

using namespace ecma;
using namespace ecma::compiler;

llvm::Module *Compiler::compile(llvm::LLVMContext &context, bool debug)
{
    llvm::Module *module = new llvm::Module(name(), context);

    if (debug)
    {
        llvm::verifyModule(*module);
    }

    return module;
}
