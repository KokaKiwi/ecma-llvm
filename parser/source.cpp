#include <string>
#include <fstream>
#include "ecma/toolchain/source.h"
#include "ecma/lex/lexer.h"
#include "ecma/parser/parser.h"
#include "ecma/ast/stmt/block.h"

using namespace ecma;
using namespace ecma::toolchain;

ast::stmt::Block *Source::parse() const
{
    lex::Lexer lexer(m_source);
    parser::Parser parser(lexer);

    parser.exec();

    return parser.program();
}

Source Source::fromString(const std::string &source)
{
    return Source("*inline*", source);
}

Source Source::fromFile(const std::string &path)
{
    std::ifstream stream(path);
    std::string::size_type position = path.rfind('/');
    std::string filename = position != std::string::npos ? path.substr(position) : path;

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
