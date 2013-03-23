#include <vector>
#include <string>
#include <sstream>
#include "ecma/lex/lexeme.h"
#include "ecma/parser/exception.h"

using namespace ecma;
using parser::Exception;

Exception::Exception(const std::string &message, const lex::Lexeme &lexeme, const std::vector<std::string> &expected_tokens)
    : m_message(message)
    , m_lexeme(lexeme)
    , m_expected_tokens(expected_tokens)
{
    std::ostringstream strstream;

    strstream << message << " " << lex::Lexeme::typeString(lexeme.type()) << " at line " << lexeme.position().first << ", column " << lexeme.position().second;

    if (!expected_tokens.empty())
    {
        auto last_expected = (++expected_tokens.rbegin()).base();

        strstream << " (expected ";

        for (auto it = expected_tokens.begin(); it != expected_tokens.end(); ++it)
        {
            if (it != expected_tokens.begin())
            {
                if (it != last_expected)
                {
                    strstream << ", ";
                }
                else if (it == last_expected)
                {
                    strstream << " or ";
                }
            }

            strstream << *it;
        }

        strstream << ")";
    }

    m_what = strstream.str();
}
