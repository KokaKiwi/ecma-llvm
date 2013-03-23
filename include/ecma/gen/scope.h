#ifndef ECMA_GEN_SCOPE_H_
#define ECMA_GEN_SCOPE_H_

#include <map>
#include <string>
#include <memory>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/IRBuilder.h>
#include <llvm/Value.h>
#include <llvm/Type.h>

namespace ecma
{
    namespace gen
    {
        class Scope
        {
        public:
            Scope(llvm::LLVMContext &context, llvm::IRBuilder<> irBuilder): m_context(context), m_irBuilder(irBuilder) {}

            llvm::Value *declare(const std::string &name, llvm::Type *type);

            llvm::Value *set(const std::string &name, llvm::Value *value);
            llvm::Value *get(const std::string &name);

        private:
            llvm::LLVMContext &m_context;
            llvm::IRBuilder<> m_irBuilder;

            std::map<std::string, llvm::Value *> m_variables;
        };
    }
}

#endif /* ECMA_GEN_SCOPE_H_ */
