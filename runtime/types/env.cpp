#include <vector>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include "ecma/runtime/types/env.h"
#include "ecma/runtime/types/env_entry.h"
#include "llvmpp/helper/type.h"
#include "llvmpp/Object.h"

using namespace ecma;
using namespace ecma::runtime;
using namespace ecma::runtime::types;

llvm::Type *Env::ConstructType() const
{
    llvm::StructType *type = llvm::StructType::create(Context, "ecma.env");
    std::vector<llvm::Type *> members;

    members.push_back(llvm::PointerType::get(type, 0));

    members.push_back(llvmpp::helper::type<unsigned int>(Context));

    EnvEntry entryClass(Context);
    members.push_back(entryClass.GetPointerType());

    type->setBody(members);
    return type;
}
