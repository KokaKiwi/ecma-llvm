#ifndef ECMA_COMPILER_FUNCTION_H_
#define ECMA_COMPILER_FUNCTION_H_

#include <string>
#include <vector>
#include <memory>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include "ecma/ast/statement.h"

namespace ecma
{
    namespace compiler
    {
        class Function
        {
        public:
            inline Function(llvm::Module *module, const std::string &name)
                : m_module(module)
                , m_name(name)
            {}

            void compile(llvm::LLVMContext &context, const std::vector<std::unique_ptr<ast::Statement>> &statements);

            inline llvm::Module *module()
            {
                return m_module;
            }

            inline const std::string &name() const
            {
                return m_name;
            }

        private:
            llvm::Module *m_module;
            std::string m_name;
        };
    }
}

#endif /* ECMA_COMPILER_FUNCTION_H_ */
