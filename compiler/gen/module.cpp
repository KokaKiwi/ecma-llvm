#include <string>
#include "ecma/llvm_ir.h"
#include "ecma/gen/module.h"
#include "ecma/gen/helper/type.h"
#include "ecma/ast/stmt/block.h"

using namespace ecma;
using namespace ecma::gen;

ModuleBuilder::ModuleBuilder(const std::string &name, ast::stmt::Block *program)
    : m_name(name)
    , m_program(program)
{

}

void ModuleBuilder::build(llvm::LLVMContext &context, llvm::Module *module)
{
    std::string entryFunctionName = "module_" + m_name;
    llvm::Function *entryFunction = llvm::Function::Create(gen::helper::type<void (void)>(context), llvm::GlobalVariable::ExternalLinkage, entryFunctionName, module);

    llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(context, "entry");

    entryFunction->getBasicBlockList().push_back(entryBlock);

    llvm::IRBuilder<> irBuilder(context);
    irBuilder.SetInsertPoint(entryBlock);

    llvm::BasicBlock &lastBlock = entryFunction->getBasicBlockList().back();
    if (lastBlock.empty() || !lastBlock.back().isTerminator())
    {
        irBuilder.SetInsertPoint(&lastBlock, lastBlock.end());
        irBuilder.CreateRetVoid();
    }
}
