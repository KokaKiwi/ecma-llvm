#include <string>
#include <stdexcept>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/BasicBlock.h>
#include <llvm/TypeBuilder.h>
#include <llvm/Constants.h>
#include <llvm/IRBuilder.h>
#include <llvm/Value.h>
#include "ecma/gen/scope.h"
#include "ecma/gen/helper/type.h"
#include "ecma/runtime/object.h"

using namespace ecma;
using namespace ecma::gen;

llvm::Value *Scope::declare(llvm::IRBuilder<> &irBuilder, const std::string &name, llvm::Value *initializer)
{
    if (m_variables.find(name) != m_variables.end())
    {
        throw std::runtime_error("Multiple variable redefinition.");
    }

    llvm::Value *dummy = irBuilder.CreateAlloca(gen::helper::type<runtime::Object *>(m_context), nullptr, name);
    m_variables[name] = dummy;

    if (initializer)
    {
        set(irBuilder, name, initializer);
    }

    return dummy;
}

llvm::Value *Scope::get(llvm::IRBuilder<> &irBuilder, const std::string &name)
{
    llvm::Value *dummy = descriptor(name);

    if (dummy == nullptr)
    {
        throw std::runtime_error("Undeclared variable: " + name);
    }

    return irBuilder.CreateLoad(dummy, name);
}

llvm::Value *Scope::set(llvm::IRBuilder<> &irBuilder, const std::string &name, llvm::Value *value)
{
    llvm::Value *dummy = descriptor(name);

    if (dummy == nullptr)
    {
        dummy = declare(irBuilder, name);
    }

    return irBuilder.CreateStore(value, dummy);
}

llvm::Value *Scope::descriptor(const std::string &name)
{
    auto it = m_variables.find(name);

    if (it != m_variables.end())
    {
        return it->second;
    }
    if (m_parent != nullptr)
    {
        return m_parent->descriptor(name);
    }

    return nullptr;
}
