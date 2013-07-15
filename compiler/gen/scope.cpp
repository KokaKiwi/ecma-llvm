#include <string>
#include <stdexcept>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/TypeBuilder.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>
#include "ecma/gen/scope.h"
#include "ecma/gen/helper/type.h"
#include "ecma/gen/helper/string.h"
#include "ecma/runtime/object.h"
#include "ecma/runtime/capi.call.h"

using namespace ecma;
using namespace ecma::gen;

Scope &Scope::declare(llvm::IRBuilder<> &irBuilder, const std::string &name, llvm::Value *initializer)
{
    if (m_resolver->has(name))
    {
        throw std::runtime_error("Multiple variable redefinition.");
    }

    if (initializer == nullptr)
    {
        initializer = Ecma_Undefined_create(m_context, m_module, irBuilder);
    }
    Ecma_setProperty(m_context, m_module, irBuilder, m_env, gen::helper::string(irBuilder, name), initializer);
    m_resolver->add(name);

    return *this;
}

llvm::Value *Scope::get(llvm::IRBuilder<> &irBuilder, const std::string &name)
{
    if (m_resolver->has(name))
    {
        llvm::Value *value = Ecma_getProperty(m_context, m_module, irBuilder, m_env, gen::helper::string(irBuilder, name));
        value->setName(name);
        return value;
    }
    if (m_parent != nullptr)
    {
        return m_parent->get(irBuilder, name);
    }

    m_resolver->add(name);
    throw std::runtime_error("Undeclared variable: " + name);
}

Scope &Scope::set(llvm::IRBuilder<> &irBuilder, const std::string &name, llvm::Value *value)
{
    if (m_resolver->has(name))
    {
        Ecma_setProperty(m_context, m_module, irBuilder, m_env, gen::helper::string(irBuilder, name), value);
    }
    else if (m_parent != nullptr)
    {
        m_parent->set(irBuilder, name, value);
    }
    else
    {
        declare(irBuilder, name, value);
    }

    return *this;
}

bool Scope::has(const std::string &name)
{
    if (m_resolver->has(name))
    {
        return true;
    }
    if (m_parent != nullptr)
    {
        return m_parent->has(name);
    }

    return false;
}
