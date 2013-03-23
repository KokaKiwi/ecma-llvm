#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/IRBuilder.h>
#include "ecma/gen/scope.h"
#include "ecma/ast/stmt/block.h"
#include "ecma/gen/code_builder.h"
#include "ecma/gen/svisitor.h"

using namespace ecma;
using namespace ecma::gen;

void CodeBuilder::build(llvm::LLVMContext &context, llvm::Module *module, llvm::IRBuilder<> &irBuilder, gen::Scope &scope)
{
    SVisitor visitor(context, module, irBuilder, scope);

    m_program->accept(visitor);
}
