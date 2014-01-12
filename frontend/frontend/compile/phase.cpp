#include <vector>
#include <memory>
#include <iostream>
#include "ecma/frontend/args.h"
#include "ecma/frontend/unit.h"
#include "ecma/frontend/compile/phase.h"
#include "ecma/compiler/compiler.h"
#include "ecma/utils/messages.h"

using namespace ecma;
using namespace ecma::frontend;
using namespace ecma::frontend::compile;

static std::string basename(const std::string &path)
{
    auto start = path.find_last_of(PATH_SEPARATOR) + 1;
    auto end = path.find_last_of('.');
    return path.substr(start, end - start);
}

Phase::Result Compile::run(std::vector<std::unique_ptr<Unit>> &units)
{
    bool success = true;

    for (auto it = units.begin(); it != units.end(); ++it)
    {
        std::string name = basename((*it)->source().name());
        if (name == "-")
        {
            name = "stdin";
        }
        auto module = compiler::Compiler::compile((*it)->ast_module(), (*it)->llvm_context(), name);
        (*it)->llvm_module(module);

        if (!module)
        {
            success = false;
        }
    }

    if (utils::Messages::HasErrors() || !success)
    {
        return Phase::Result::ERROR;
    }

    return Phase::Result::CONTINUE;
}
