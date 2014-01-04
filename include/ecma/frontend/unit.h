#ifndef ECMA_FRONTEND_UNIT_H_
#define ECMA_FRONTEND_UNIT_H_

#include <memory>
#include <string>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include "ecma/parser/toolchain/source.h"
#include "ecma/ast/module.h"

namespace ecma
{
    namespace frontend
    {
        class Unit
        {
        public:
            inline Unit(parser::toolchain::Source *source)
                : m_source(source)
            {}

            inline parser::toolchain::Source &source() const
            {
                return *m_source;
            }

            inline const ast::Module *ast_module() const
            {
                return m_ast_module.get();
            }
            inline Unit &ast_module(ast::Module *ast_module)
            {
                m_ast_module.reset(ast_module);
                return *this;
            }
            inline ast::Module *take_ast_module()
            {
                return m_ast_module.release();
            }

            inline const llvm::Module *llvm_module() const
            {
                return m_llvm_module.get();
            }
            inline Unit &llvm_module(llvm::Module *llvm_module)
            {
                m_llvm_module.reset(llvm_module);
                return *this;
            }
            inline llvm::Module *take_llvm_module()
            {
                return m_llvm_module.release();
            }

            inline llvm::LLVMContext &llvm_context()
            {
                return m_llvm_context;
            }

        private:
            std::unique_ptr<parser::toolchain::Source> m_source;

            std::unique_ptr<ast::Module> m_ast_module;

            llvm::LLVMContext m_llvm_context;
            std::unique_ptr<llvm::Module> m_llvm_module;
        };
    }
}

#endif /* ECMA_FRONTEND_UNIT_H_ */
