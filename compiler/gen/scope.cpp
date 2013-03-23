#include <stdexcept>
#include <string>
#include <llvm/IRBuilder.h>
#include <llvm/Value.h>
#include "ecma/gen/helper/type.h"
#include "ecma/gen/scope.h"

using namespace ecma;
using namespace ecma::gen;

llvm::Value *Scope::declare(const std::string &name, llvm::Type *type)
{
    llvm::Value *var = m_variables[name];

    if (var)
        throw std::runtime_error("Multiple variable definition.");

    var = m_irBuilder.CreateAlloca(type);
    m_variables[name] = var;

    return var;
}

llvm::Value *Scope::set(const std::string &name, llvm::Value *value)
{
    llvm::Value *var = m_variables[name];

    if (!var)
        var = declare(name, value->getType());

    m_irBuilder.CreateStore(value, var);

    return var;
}

llvm::Value *Scope::get(const std::string &name)
{
    llvm::Value *var = m_variables[name];

    if (!var)
        throw std::runtime_error("Undeclared variable.");

    return m_irBuilder.CreateLoad(var);
}
