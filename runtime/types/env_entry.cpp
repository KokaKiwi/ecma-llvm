#include <vector>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include "ecma/runtime/types/env_entry.h"
#include "llvmpp/helper/type.h"

using namespace ecma;
using namespace ecma::runtime;
using namespace ecma::runtime::types;

llvm::Type *EnvEntry::ConstructType() const
{
    llvm::StructType *type = llvm::StructType::create(Context, "ecma.env.entry");
    std::vector<llvm::Type *> members;

    members.push_back(llvmpp::helper::type<char *>(Context));

    type->setBody(members);
    return type;
}
