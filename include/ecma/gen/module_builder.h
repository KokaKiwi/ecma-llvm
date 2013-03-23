#ifndef ECMA_GEN_MODULE_BUILDER_H_
#define ECMA_GEN_MODULE_BUILDER_H_

#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include "ecma/ast/stmt/block.h"

namespace ecma
{
    namespace gen
    {
        class ModuleBuilder
        {
        public:
            inline ModuleBuilder(): m_program(nullptr) {}

            llvm::Module *build(llvm::LLVMContext &context, llvm::Module *module) const;

            inline ast::stmt::Block *program(void) const
            {
                return m_program;
            }
            inline ModuleBuilder &program(ast::stmt::Block *program)
            {
                m_program = program;
                return *this;
            }

        private:
            ast::stmt::Block *m_program;
        };
    }
}

#endif /* ECMA_GEN_MODULE_BUILDER_H_ */
