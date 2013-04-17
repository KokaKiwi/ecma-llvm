#include <llvm/Module.h>
#include <llvm/Analysis/Verifier.h>
#include "config.h"
#include "ecma/ast/stmt/block.h"
#include "ecma/toolchain/source.h"
#include "ecma/toolchain/compiler.h"

using namespace ecma;
using namespace ecma::toolchain;

llvm::Module *Compiler::build(const std::string &name, const Source &source)
{
    return build(name, source.parse());
}

llvm::Module *Compiler::build(const std::string &name, ast::stmt::Block *program)
{
    llvm::Module *module = new llvm::Module(name, m_context);

#ifdef DEBUG
    llvm::verifyModule(*module);
#endif /* DEBUG */

    return module;
}
