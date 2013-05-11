#ifndef ECMA_GEN_FUNCTION_H_
#define ECMA_GEN_FUNCTION_H_

#include <string>
#include <llvm/Value.h>
#include <llvm/LLVMContext.h>
#include <llvm/IRBuilder.h>
#include "ecma/ast/expr/literal/function.h"
#include "ecma/gen/scope.h"

namespace ecma
{
    namespace gen
    {
        class FunctionBuilder
        {
        public:
            inline FunctionBuilder(const std::string &name = "", ast::expr::literal::Function *function = nullptr): m_name(name), m_function(function) {}

            llvm::Value *build(llvm::LLVMContext &context, llvm::Module *module, llvm::IRBuilder<> &irBuilder, Scope &scope);

            inline const std::string &name(void) const
            {
                return m_name;
            }
            inline FunctionBuilder &name(std::string &name)
            {
                m_name = name;
                return *this;
            }

            inline ast::expr::literal::Function *function(void) const
            {
                return m_function;
            }
            inline FunctionBuilder &function(ast::expr::literal::Function *function)
            {
                m_function = function;
                return *this;
            }

        private:
            std::string m_name;
            ast::expr::literal::Function *m_function;
        };
    }
}

#endif /* ECMA_GEN_FUNCTION_H_ */
