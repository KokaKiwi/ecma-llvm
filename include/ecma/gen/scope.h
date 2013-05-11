#ifndef ECMA_GEN_SCOPE_H_
#define ECMA_GEN_SCOPE_H_

#include <string>
#include <map>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/BasicBlock.h>
#include <llvm/IRBuilder.h>
#include <llvm/Value.h>

namespace ecma
{
    namespace gen
    {
        class Scope
        {
        public:
            inline Scope(llvm::LLVMContext &context, llvm::Module *module, Scope *parent = nullptr): m_context(context), m_module(module), m_parent(parent) {}

            llvm::Value *declare(llvm::IRBuilder<> &irBuilder, const std::string &name, llvm::Value *initializer = nullptr);
            llvm::Value *get(llvm::IRBuilder<> &irBuilder, const std::string &name);
            llvm::Value *set(llvm::IRBuilder<> &irBuilder, const std::string &name, llvm::Value *value);

            llvm::Value *descriptor(const std::string &name);

            inline const llvm::LLVMContext &context(void) const
            {
                return m_context;
            }

            inline const llvm::Module *module(void) const
            {
                return m_module;
            }

            inline const Scope *parent(void) const
            {
                return m_parent;
            }

        private:
            llvm::LLVMContext &m_context;
            llvm::Module *m_module;
            Scope *m_parent;

            std::map<std::string, llvm::Value *> m_variables;
        };
    }
}

#endif /* ECMA_GEN_SCOPE_H_ */
