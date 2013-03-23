#ifndef ECMA_GEN_EVISITOR_H_
#define ECMA_GEN_EVISITOR_H_

#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/IRBuilder.h>
#include <llvm/Type.h>
#include <llvm/Value.h>
#include "ecma/gen/scope.h"
#include "ecma/ast/node.h"
#include "ecma/ast/tools/visitor.h"
#include "ecma/gen/svisitor.h"
#include "ecma/ast/expr/assignment.h"
#include "ecma/ast/expr/binary.h"
#include "ecma/ast/expr/unary.h"
#include "ecma/ast/expr/literal/function_call.h"
#include "ecma/ast/expr/literal/identifier.h"
#include "ecma/ast/expr/literal/number.h"
#include "ecma/ast/expr/literal/string.h"

namespace ecma
{
    namespace gen
    {
        class EVisitor: public ast::tools::Visitor
        {
        public:
            inline EVisitor(llvm::LLVMContext &context, llvm::Module *module, llvm::IRBuilder<> &irBuilder, gen::Scope &scope): m_context(context), m_module(module), m_irBuilder(irBuilder), m_scope(scope) {}
            inline EVisitor(gen::SVisitor &visitor): EVisitor(visitor.context(), visitor.module(), visitor.irBuilder(), visitor.scope()) {}

            void visit(ast::expr::Assignment &assign);
            void visit(ast::expr::Binary &binary);
            void visit(ast::expr::Unary &unary);
            void visit(ast::expr::literal::FunctionCall &call);
            void visit(ast::expr::literal::Identifier &identifier);
            void visit(ast::expr::literal::Number &number);
            void visit(ast::expr::literal::String &string);

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

            inline llvm::Value *value(void) const
            {
                return m_value;
            }

            inline llvm::Value *run(ast::Node &node)
            {
                node.accept(*this);

                return value();
            }

        private:
            llvm::LLVMContext &m_context;
            llvm::Module *m_module;
            llvm::IRBuilder<> &m_irBuilder;
            gen::Scope &m_scope;

            llvm::Value *m_value;
        };
    }
}

#endif /* ECMA_GEN_EVISITOR_H_ */
