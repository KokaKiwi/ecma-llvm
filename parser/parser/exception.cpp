#include <sstream>
#include "ecma/parser/exception.h"
#include "ecma/utils/messages.h"

using namespace ecma;
using namespace ecma::parser;

void UnexpectedToken::printMessage()
{
    std::ostringstream ss;

    ss << "Unexpected token: " << m_token.toString();

    if (!m_expected.empty())
    {
        auto last_expected = (++m_expected.rbegin()).base();

        ss << " (expected ";

        for (auto it = m_expected.begin(); it != m_expected.end(); ++it)
        {
            if (it != m_expected.begin())
            {
                if (it != last_expected)
                {
                    ss << ", ";
                }
                else if (it == last_expected)
                {
                    ss << " or ";
                }
            }

            ss << *it;
        }

        ss << ")";
    }

    uint length = m_token.text().length();
    utils::Messages::ReportError(ss.str(), m_token.pos(), length > 0 ? length - 1 : 0);
}
