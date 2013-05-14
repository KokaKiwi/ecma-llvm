#ifndef ECME_GEN_GPEVISITOR_H_
#define ECME_GEN_GPEVISITOR_H_

#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/IRBuilder.h>
#include <llvm/Value.h>
#include "ecma/gen/scope.h"
#include "ecma/ast/tools/visitor.h"
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace gen
    {
        class GPEVisitor: public ast::tools::Visitor
        {
        public:
            inline GPEVisitor(llvm::LLVMContext &context, llvm::Module *module, llvm::IRBuilder<> &irBuilder, Scope &scope): m_context(context), m_module(module), m_irBuilder(irBuilder), m_scope(scope), m_value(nullptr) {}

            virtual void visit(ast::expr::Assign &assign);
            virtual void visit(ast::expr::Identifier &id);
            virtual void visit(ast::expr::Member &member);
            virtual void visit(ast::expr::Index &index);
            virtual void visit(ast::expr::Binary &binary);
            virtual void visit(ast::expr::Unary &unary);
            virtual void visit(ast::expr::Object &object);
            virtual void visit(ast::expr::Array &array);
            virtual void visit(ast::expr::Call &call);
            virtual void visit(ast::expr::Conditional &cond);
            virtual void visit(ast::expr::This &thisExpr);
            virtual void visit(ast::expr::Extern &expr);

            virtual void visit(ast::expr::literal::Integer &integer);
            virtual void visit(ast::expr::literal::Boolean &boolean);
            virtual void visit(ast::expr::literal::String &str);
            virtual void visit(ast::expr::literal::Null &null);
            virtual void visit(ast::expr::literal::Undefined &undef);
            virtual void visit(ast::expr::literal::Function &function);

            inline llvm::Value *run(ast::Node &node)
            {
                node.accept(*this);
                return m_value;
            }

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

            inline llvm::Value *value(void) const
            {
                return m_value;
            }

        private:
            llvm::LLVMContext &m_context;
            llvm::Module *m_module;
            llvm::IRBuilder<> &m_irBuilder;
            Scope &m_scope;
            llvm::Value *m_value;
        };
    }
}

#endif /* ECME_GEN_GPEVISITOR_H_ */
