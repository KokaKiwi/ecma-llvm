#include "config.h"
#include "ecma/llvm_ir.h"
#include "ecma/ast/stmt/block.h"
#include "ecma/toolchain/source.h"
#include "ecma/toolchain/compiler.h"
#include "ecma/gen/helper/type.h"
#include "ecma/gen/module.h"

using namespace ecma;
using namespace ecma::toolchain;

Compiler::Compiler(): m_context()
{

}

llvm::Module *Compiler::build(const std::string &name, const Source &source)
{
    ast::stmt::Block *program = source.parse();
    llvm::Module *module = build(name, program);

    delete program;
    return module;
}

llvm::Module *Compiler::build(const std::string &name, ast::stmt::Block *program)
{
    llvm::Module *module = new llvm::Module(name, m_context);

    gen::ModuleBuilder(name, program)
        .build(m_context, module);

#ifdef DEBUG
    llvm::verifyModule(*module);
#endif /* DEBUG */

    return module;
}
