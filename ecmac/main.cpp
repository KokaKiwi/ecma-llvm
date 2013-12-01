#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <llvm/Support/raw_ostream.h>
#include "ecma/llvm_ir.h"
#include "ecma/parser/exception.h"
#include "ecma/toolchain/source.h"
#include "ecma/toolchain/compiler.h"
#include "ecma/ast/tools/print_visitor.h"

using namespace ecma;

#define DEBUG false

int main(int argc, char **argv)
{
    toolchain::Compiler compiler;
    ast::stmt::Block *program;
    llvm::Module *module;
    std::string moduleName;
    ast::tools::PrintVisitor visitor(std::cerr);

    try
    {
        if (argc == 1)
        {
            program = toolchain::Source::fromStream(std::cin).parse(DEBUG);
            moduleName = "*stream*";
        }
        else if (argc == 2)
        {
            toolchain::Source source = toolchain::Source::fromFile(argv[1]);
            program = source.parse(DEBUG);
            std::string::size_type epos = source.name().find('.');
            moduleName = source.name();
            moduleName.erase(epos, moduleName.length() - epos);
        }
        else
        {
            std::cerr << "Usage: " << argv[0] << " [input file]" << std::endl;
            return EXIT_FAILURE;
        }
    }
    catch (parser::Exception &e)
    {
        std::cerr << "Parsing error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    try
    {
        program->accept(visitor);

        module = compiler.build(moduleName, program);
        module->print(llvm::outs(), nullptr);

        delete program;
        delete module;
    }
    catch (std::runtime_error &e)
    {
        std::cerr << "Compilation error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
