#ifndef ECMA_GEN_MODULE_H_
#define ECMA_GEN_MODULE_H_

#include <string>
#include "ecma/llvm_ir.h"
#include "ecma/ast/stmt/block.h"

namespace ecma
{
    namespace gen
    {
        class ModuleBuilder
        {
        public:
            ModuleBuilder(const std::string &name, ast::stmt::Block *program = nullptr);

            void build(llvm::LLVMContext &context, llvm::Module *module);

            inline const std::string &name(void) const
            {
                return m_name;
            }

            inline ast::stmt::Block *program(void) const
            {
                return m_program;
            }

        private:
            std::string m_name;
            ast::stmt::Block *m_program;
        };
    }
}

#endif /* ECMA_GEN_MODULE_H_ */
