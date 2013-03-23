#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <llvm/Module.h>
#include <llvm/Support/raw_ostream.h>
#include "ecma/parser/exception.h"
#include "ecma/toolchain/source.h"
#include "ecma/toolchain/compiler.h"

using namespace ecma;

int main(int argc, char **argv)
{
    toolchain::Compiler compiler;
    ast::stmt::Block *program;
    llvm::Module *module;

    try
    {
        if (argc == 1)
        {
            program = toolchain::Source::fromStream(std::cin).parse();
        }
        else if (argc == 2)
        {
            program = toolchain::Source::fromFile(argv[1]).parse();
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
        module = compiler.build(argv[1], program);
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
