#include "ecma/compiler/compiler.h"
#include "llvm_ir.h"

using namespace ecma;
using namespace ecma::compiler;

llvm::Module *Compiler::compile(bool debug)
{
    llvm::LLVMContext &context = llvm::getGlobalContext();

    return new llvm::Module(name(), context);
}
