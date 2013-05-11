#ifndef ECMA_GEN_SVISITOR_H_
#define ECMA_GEN_SVISITOR_H_

#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/IRBuilder.h>
#include "ecma/gen/scope.h"
#include "ecma/ast/tools/visitor.h"
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace gen
    {
        class SVisitor: public ast::tools::Visitor
        {
        public:
            inline SVisitor(llvm::LLVMContext &context, llvm::Module *module, llvm::IRBuilder<> &irBuilder, Scope &scope): m_context(context), m_module(module), m_irBuilder(irBuilder), m_scope(scope) {}

            virtual void visit(ast::stmt::Expression &stmt);
            virtual void visit(ast::stmt::Block &block);
            virtual void visit(ast::stmt::Return &ret);
            virtual void visit(ast::stmt::decl::Variables &vars);
            virtual void visit(ast::stmt::decl::Function &function);
            virtual void visit(ast::stmt::ctrl::If &stmt);
            virtual void visit(ast::stmt::ctrl::While &stmt);

            inline const llvm::LLVMContext &context(void) const
            {
                return m_context;
            }

            inline const llvm::Module *module(void) const
            {
                return m_module;
            }

            inline const llvm::IRBuilder<> &irBuilder(void) const
            {
                return m_irBuilder;
            }

            inline const Scope &scope(void) const
            {
                return m_scope;
            }

        private:
            llvm::LLVMContext &m_context;
            llvm::Module *m_module;
            llvm::IRBuilder<> &m_irBuilder;
            Scope &m_scope;
        };
    }
}

#endif /* ECMA_GEN_SVISITOR_H_ */
