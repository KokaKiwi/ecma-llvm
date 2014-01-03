#include <string>
#include <fstream>
#include "ecma/lex/lexer.h"
#include "ecma/parser/parser.h"
#include "ecma/parser/toolchain/source.h"
#include "ecma/utils/messages.h"
#include "ecma/ast/ast.h"

using namespace ecma;
using namespace ecma::parser;
using namespace ecma::parser::toolchain;

Source::Source(const std::string &name, const std::string &source)
    : m_name(name)
    , m_source(source)
{
}

ast::Module *Source::parse(bool debug) const
{
    lex::Lexer lexer(m_source);
    parser::Parser parser;

    updateEnv();
    parser.debug(debug).parse(lexer);

    return parser.module();
}

void Source::updateEnv() const
{
    utils::Messages::SetSourceName(m_name == "-" ? "stdin" : m_name);
    utils::Messages::SetSource(m_source);
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
