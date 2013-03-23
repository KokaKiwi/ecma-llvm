#ifndef ECMA_GEN_SVISITOR_H_
#define ECMA_GEN_SVISITOR_H_

#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/IRBuilder.h>
#include "ecma/gen/scope.h"
#include "ecma/ast/tools/visitor.h"
#include "ecma/ast/stmt/block.h"
#include "ecma/ast/stmt/expression.h"
#include "ecma/ast/stmt/return.h"
#include "ecma/ast/stmt/decl/variables.h"

namespace ecma
{
    namespace gen
    {
        class SVisitor: public ast::tools::Visitor
        {
        public:
            inline SVisitor(llvm::LLVMContext &context, llvm::Module *module, llvm::IRBuilder<> &irBuilder, gen::Scope &scope): m_context(context), m_module(module), m_irBuilder(irBuilder), m_scope(scope) {}

            void visit(ast::stmt::Block &block);
            void visit(ast::stmt::Expression &expr);
            void visit(ast::stmt::Return &ret);
            void visit(ast::stmt::decl::Variables &vars);

            inline llvm::LLVMContext &context(void) const
            {
                return m_context;
            }

            inline llvm::Module *module(void) const
            {
                return m_module;
            }

            inline llvm::IRBuilder<> &irBuilder(void) const
            {
                return m_irBuilder;
            }

            inline gen::Scope &scope(void) const
            {
                return m_scope;
            }

        private:
            llvm::LLVMContext &m_context;
            llvm::Module *m_module;
            llvm::IRBuilder<> &m_irBuilder;
            gen::Scope &m_scope;
        };
    }
}

#endif /* ECMA_GEN_SVISITOR_H_ */
