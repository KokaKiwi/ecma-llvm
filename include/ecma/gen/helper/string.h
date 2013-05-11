#ifndef ECMA_GEN_HELPER_STRING_H_
#define ECMA_GEN_HELPER_STRING_H_

#include <string>
#include <llvm/Value.h>
#include <llvm/IRBuilder.h>

namespace ecma
{
    namespace gen
    {
        namespace helper
        {
            inline llvm::Value *string(llvm::IRBuilder<> &irBuilder, const std::string &str)
            {
                return irBuilder.CreateGlobalStringPtr(str);
            }
        }
    }
}

#endif /* ECMA_GEN_HELPER_STRING_H_ */
