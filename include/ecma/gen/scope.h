#ifndef ECMA_GEN_SCOPE_H_
#define ECMA_GEN_SCOPE_H_

#include <string>
#include <vector>
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
            class Resolver
            {
            public:
                inline bool has(const std::string &name)
                {
                    return std::find(m_variables.begin(), m_variables.end(), name) != m_variables.end();
                }

                inline void add(const std::string &name)
                {
                    m_variables.push_back(name);
                }

            private:
                std::vector<std::string> m_variables;
            };

            inline Scope(llvm::LLVMContext &context, llvm::Module *module, llvm::Value *env, Resolver *resolver = new Resolver(), Scope *parent = nullptr)
                : m_context(context)
                , m_module(module)
                , m_env(env)
                , m_resolver(resolver)
                , m_parent(parent)
                , m_thisValue(nullptr)
            {}

            Scope &declare(llvm::IRBuilder<> &irBuilder, const std::string &name, llvm::Value *initializer = nullptr);
            llvm::Value *get(llvm::IRBuilder<> &irBuilder, const std::string &name);
            Scope &set(llvm::IRBuilder<> &irBuilder, const std::string &name, llvm::Value *value);

            bool has(const std::string &name);

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

            inline llvm::Value *env(void) const
            {
                return m_env;
            }

            inline llvm::Value *thisValue(void) const
            {
                return m_thisValue;
            }
            inline Scope &thisValue(llvm::Value *thisValue)
            {
                m_thisValue = thisValue;
                return *this;
            }

            inline Resolver *resolver(void) const
            {
                return m_resolver;
            }

        private:
            llvm::LLVMContext &m_context;
            llvm::Module *m_module;
            Scope *m_parent;
            llvm::Value *m_env;
            llvm::Value *m_thisValue;

            Resolver *m_resolver;
        };
    }
}

#endif /* ECMA_GEN_SCOPE_H_ */
