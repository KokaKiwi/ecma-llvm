#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/IRBuilder.h>
#include "ecma/ast/statement.h"
#include "ecma/gen/code.h"
#include "ecma/gen/scope.h"
#include "ecma/gen/svisitor.h"

using namespace ecma;
using namespace ecma::gen;

void CodeBuilder::build(llvm::LLVMContext &context, llvm::Module *module, llvm::IRBuilder<> &irBuilder, Scope &scope) const
{
    SVisitor visitor(context, module, irBuilder, scope);

    for (ast::Statement *stmt : m_statements->statements())
    {
        stmt->accept(visitor);
    }
}
