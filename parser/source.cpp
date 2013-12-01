#include <string>
#include <iostream>
#include <fstream>
#include <libgen.h>
#include "ecma/toolchain/source.h"
#include "ecma/lex/lexer.h"
#include "ecma/parser/parser.h"
#include "ecma/ast/stmt/block.h"

using namespace ecma;
using namespace ecma::toolchain;

ast::stmt::Block *Source::parse(bool debug) const
{
    lex::Lexer lexer(m_source);
    parser::Parser parser(lexer);

    parser.debug(debug).exec();

    return parser.program();
}

Source Source::fromString(const std::string &source)
{
    return Source("*inline*", source);
}

Source Source::fromFile(const std::string &path)
{
    std::ifstream stream(path);
    std::string::size_type pos = path.rfind('/');
    std::string filename = path.substr(pos + 1, path.length() - (pos + 1));

    std::istreambuf_iterator<char> eos;
    std::string source(std::istreambuf_iterator<char>(stream), eos);

    return Source(filename, source);
}

Source Source::fromStream(std::istream &stream)
{
    std::istreambuf_iterator<char> eos;
    std::string source(std::istreambuf_iterator<char>(stream), eos);

    return Source("*stream*", source);
}
