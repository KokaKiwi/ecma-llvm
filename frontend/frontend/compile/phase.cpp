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

void Compile::init(Args &args)
{
    args.add("", false, 0, 0, "Compile only; do not assemble or link", "-S");
    args.add("", false, 0, 0, "Produce an LLVM assembly file if used with -S option;\nproduce an LLVM bitcode file otherwise", "--emit-llvm");
}

Phase::Result Compile::run(Args &args, std::vector<std::unique_ptr<Unit>> &units)
{
    bool success = true;

    for (auto it = units.begin(); it != units.end(); ++it)
    {
        bool debug = args.hasCompilerFlag("compile-debug") || args.hasCompilerFlag("debug");
        std::string name = basename((*it)->source().name());
        if (name == "-")
        {
            name = "stdin";
        }
        auto module = compiler::Compiler::compile((*it)->ast_module(), name, debug);
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
