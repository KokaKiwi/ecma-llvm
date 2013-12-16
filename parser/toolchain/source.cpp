#include <string>
#include <fstream>
#include "ecma/lex/lexer.h"
#include "ecma/parser/parser.h"
#include "ecma/toolchain/source.h"
#include "ecma/utils/messages.h"
#include "ecma/ast/ast.h"

using namespace ecma;
using namespace ecma::toolchain;

Source::Source(const std::string &name, const std::string &source)
    : m_name(name)
    , m_source(source)
{
    utils::Messages::SetSourceName(name);
    utils::Messages::SetSource(source);
}

ast::Module *Source::parse(bool debug) const
{
    lex::Lexer lexer(m_source);
    parser::Parser parser;

    parser.debug(debug).parse(lexer);

    return parser.module();
}

Source *Source::fromString(const std::string &source, const std::string &name)
{
    return new Source(name, source);
}

Source *Source::fromFile(const std::string &path)
{
    std::ifstream stream(path);

    return fromStream(stream, path);
}

Source *Source::fromStream(std::istream &stream, const std::string &name)
{
    std::istreambuf_iterator<char> eos;
    std::string source(std::istreambuf_iterator<char>(stream), eos);

    return new Source(name, source);
}
