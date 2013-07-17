#ifndef ECMA_TOOLCHAIN_COMPILER_H_
#define ECMA_TOOLCHAIN_COMPILER_H_

#include <string>
#include "ecma/llvm_ir.h"
#include "ecma/toolchain/source.h"
#include "ecma/ast/stmt/block.h"

namespace ecma
{
    namespace toolchain
    {
        class Compiler
        {
        public:
            Compiler();

            llvm::Module *build(const std::string &name, const Source &source);
            llvm::Module *build(const std::string &name, ast::stmt::Block *program);

        private:
            llvm::LLVMContext m_context;
        };
    }
}

#endif /* ECMA_TOOLCHAIN_COMPILER_H_ */
