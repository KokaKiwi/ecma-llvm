#ifndef ECMA_GEN_CODE_BUILDER_H_
#define ECMA_GEN_CODE_BUILDER_H_

#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/IRBuilder.h>
#include "ecma/gen/scope.h"
#include "ecma/ast/stmt/block.h"

namespace ecma
{
    namespace gen
    {
        class CodeBuilder
        {
        public:
            inline CodeBuilder(): m_program(nullptr) {}

            inline ast::stmt::Block *program(void) const
            {
                return m_program;
            }
            inline CodeBuilder &program(ast::stmt::Block *program)
            {
                m_program = program;
                return *this;
            }

            void build(llvm::LLVMContext &context, llvm::Module *module, llvm::IRBuilder<> &irBuilder, gen::Scope &scope);

        private:
            ast::stmt::Block *m_program;
        };
    }
}

#endif /* ECMA_GEN_CODE_BUILDER_H_ */
