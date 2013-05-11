#include <llvm/Value.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/gen/lsevisitor.h"
#include "ecma/ast/expr/index.h"
#include "ecma/runtime/capi.call.h"

using namespace ecma;
using namespace ecma::gen;

void LSEVisitor::visit(ast::expr::Index &index)
{
    llvm::Value *instance = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*index.expr());
    llvm::Value *indexValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*index.index());
    Ecma_setIndex(m_context, m_module, m_irBuilder, instance, indexValue, m_value);
}

void GPEVisitor::visit(ast::expr::Index &index)
{
    llvm::Value *instance = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*index.expr());
    llvm::Value *indexValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*index.index());
    m_value = Ecma_getIndex(m_context, m_module, m_irBuilder, instance, indexValue);
}
