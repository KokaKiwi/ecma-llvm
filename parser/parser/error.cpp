#include <string>
#include "ecma/parser/error.h"

using namespace ecma;
using namespace ecma::parser;

// http://stackoverflow.com/a/2548212/1498917
static std::string replace_all(std::string str, const std::string &remove, const std::string &insert)
{
    std::string::size_type pos = 0;
    while ((pos = str.find(remove, pos)) != std::string::npos)
    {
        str.replace(pos, remove.size(), insert);
        pos++;
    }

    return str;
}

const std::string ParsingError::message() const
{
    std::string message = m_fmt;

    message = replace_all(message, "{token}", m_token->toString());

    return message;
}
