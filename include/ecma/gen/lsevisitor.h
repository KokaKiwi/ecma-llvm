#ifndef ECME_GEN_LSEVISITOR_H_
#define ECME_GEN_LSEVISITOR_H_

#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/IRBuilder.h>
#include <llvm/Value.h>
#include "ecma/gen/scope.h"
#include "ecma/ast/tools/visitor.h"
#include "ecma/ast/node.h"
#include "ecma/ast/expr/identifier.h"

namespace ecma
{
    namespace gen
    {
        class LSEVisitor: public ast::tools::Visitor
        {
        public:
            inline LSEVisitor(llvm::LLVMContext &context, llvm::Module *module, llvm::IRBuilder<> &irBuilder, Scope &scope, llvm::Value *value = nullptr): m_context(context), m_module(module), m_irBuilder(irBuilder), m_scope(scope), m_value(value) {}

            virtual void visit(ast::expr::Identifier &id);
            virtual void visit(ast::expr::Member &member);

            inline void run(ast::Node &node)
            {
                node.accept(*this);
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

#endif /* ECME_GEN_LSEVISITOR_H_ */
