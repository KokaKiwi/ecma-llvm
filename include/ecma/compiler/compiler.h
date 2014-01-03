#ifndef ECMA_COMPILER_COMPILER_H_
#define ECMA_COMPILER_COMPILER_H_

#include "llvm_ir.h"
#include "ecma/ast/module.h"

namespace ecma
{
    namespace compiler
    {
        class Compiler
        {
        public:
            inline Compiler(const ast::Module *module, const std::string &name)
                : m_module(module)
                , m_name(name)
            {}

            inline const ast::Module *module() const
            {
                return m_module;
            }

            inline const std::string &name() const
            {
                return m_name;
            }

            llvm::Module *compile(bool debug = false);

            static inline llvm::Module *compile(const ast::Module *module, const std::string &name, bool debug = false)
            {
                return Compiler(module, name).compile(debug);
            }

        private:
            const ast::Module *m_module;
            std::string m_name;
        };
    }
}

#endif /* ECMA_COMPILER_COMPILER_H_ */
