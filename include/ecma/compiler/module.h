#ifndef ECMA_COMPILER_MODULE_H_
#define ECMA_COMPILER_MODULE_H_

#include <string>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include "ecma/ast/module.h"

namespace ecma
{
    namespace compiler
    {
        class Module
        {
        public:
            inline Module(llvm::Module *module)
                : m_module(module)
            {}

            void compile(llvm::LLVMContext &context, const ast::Module *ast, const std::string &name);

            inline llvm::Module *module()
            {
                return m_module;
            }

        private:
            llvm::Module *m_module;
        };
    }
}

#endif /* ECMA_COMPILER_MODULE_H_ */
