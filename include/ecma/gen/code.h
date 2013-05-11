#ifndef ECMA_GEN_CODE_H_
#define ECMA_GEN_CODE_H_

#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/IRBuilder.h>
#include "ecma/ast/stmt/block.h"
#include "ecma/gen/scope.h"

namespace ecma
{
    namespace gen
    {
        class CodeBuilder
        {
        public:
            inline CodeBuilder(ast::stmt::Block *statements = nullptr): m_statements(statements) {};

            void build(llvm::LLVMContext &context, llvm::Module *module, llvm::IRBuilder<> &irBuilder, Scope &scope) const;

        private:
            ast::stmt::Block *m_statements;
        };
    }
}

#endif /* ECMA_GEN_CODE_H_ */
