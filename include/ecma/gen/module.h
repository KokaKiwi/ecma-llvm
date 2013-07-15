#ifndef ECMA_GEN_MODULE_H_
#define ECMA_GEN_MODULE_H_

#include <string>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include "ecma/ast/stmt/block.h"

namespace ecma
{
    namespace gen
    {
        class ModuleBuilder
        {
        public:
            inline ModuleBuilder(const std::string &name, ast::stmt::Block *program = nullptr)
                : m_name(name)
                , m_program(program)
            {}

            llvm::Module *build(llvm::LLVMContext &context, llvm::Module *module) const;

            inline const std::string &name(void) const
            {
                return m_name;
            }
            inline ModuleBuilder &name(std::string &name)
            {
                m_name = name;
                return *this;
            }

            inline const ast::stmt::Block *program(void) const
            {
                return m_program;
            }
            inline ModuleBuilder &program(ast::stmt::Block *program)
            {
                m_program = program;
                return *this;
            }

        private:
            std::string m_name;
            ast::stmt::Block *m_program;
        };
    }
}

#endif /* ECMA_GEN_MODULE_H_ */
