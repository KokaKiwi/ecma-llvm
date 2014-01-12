#include <string>
#include <llvm/IR/LLVMContext.h>
#include "ecma/ast/module.h"
#include "ecma/compiler/module.h"
#include "ecma/compiler/function.h"

using namespace ecma;
using namespace ecma::compiler;

void Module::compile(llvm::LLVMContext &context, const ast::Module *ast, const std::string &name)
{
    std::string fn_name = "ecma.module." + name;

    Function(module(), fn_name).compile(context, ast->statements());
}

