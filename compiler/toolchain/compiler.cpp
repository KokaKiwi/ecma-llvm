#include <llvm/Module.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/DerivedTypes.h>
#include "config.h"
#include "ecma/ast/stmt/block.h"
#include "ecma/toolchain/source.h"
#include "ecma/toolchain/compiler.h"
#include "ecma/gen/helper/type.h"
#include "ecma/gen/module.h"
#include "ecma/runtime/object.h"
#include "ecma/runtime/capi.h"

using namespace ecma;
using namespace ecma::toolchain;

Compiler::Compiler(): m_context()
{
    llvm::StructType::create(m_context, "Object");
}

llvm::Module *Compiler::build(const std::string &name, const Source &source)
{
    ast::stmt::Block *program = source.parse();
    llvm::Module *module = build(name, program);

    delete program;
    return module;
}

llvm::Module *Compiler::build(const std::string &name, ast::stmt::Block *program)
{
    llvm::Module *module = new llvm::Module(name, m_context);

    #define DECLARE(NAME) llvm::Function::Create(gen::helper::type<decltype(NAME)>(m_context), llvm::GlobalValue::ExternalLinkage, #NAME, module);
    #define ECMA_FUNCTION(NAME, RETURN, ...) DECLARE(NAME)
    #define ECMA_TYPE(TYPENAME, ...) DECLARE(Ecma_##TYPENAME##_create)

    #include "ecma/runtime/capi.def.h"

    #undef ECMA_TYPE
    #undef ECMA_FUNCTION
    #undef DECLARE

    gen::ModuleBuilder(name, program)
        .build(m_context, module);

#ifdef DEBUG
    llvm::verifyModule(*module);
#endif /* DEBUG */

    return module;
}
