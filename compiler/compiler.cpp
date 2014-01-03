#include <llvm/IR/LLVMContext.h>
#include "ecma/compiler/compiler.h"

using namespace ecma;
using namespace ecma::compiler;

llvm::Module *Compiler::compile(bool debug)
{
    llvm::LLVMContext &context = llvm::getGlobalContext();

    return new llvm::Module(name(), context);
}
