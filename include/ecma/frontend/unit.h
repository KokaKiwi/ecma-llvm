#ifndef ECMA_FRONTEND_UNIT_H_
#define ECMA_FRONTEND_UNIT_H_

#include <memory>
#include "ecma/toolchain/source.h"
#include "ecma/ast/module.h"

namespace ecma
{
    namespace frontend
    {
        class Unit
        {
        public:
            inline Unit(toolchain::Source *source)
                : m_source(source)
                , m_module(nullptr)
            {}

            inline toolchain::Source &source() const
            {
                return *m_source;
            }

            inline ast::Module &module() const
            {
                return *m_module;
            }
            inline Unit &module(ast::Module *module)
            {
                m_module.reset(module);
                return *this;
            }

        private:
            std::unique_ptr<toolchain::Source> m_source;
            std::unique_ptr<ast::Module> m_module;
        };
    }
}

#endif /* ECMA_FRONTEND_UNIT_H_ */
