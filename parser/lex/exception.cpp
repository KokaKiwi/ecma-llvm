#include <sstream>
#include "ecma/lex/exception.h"
#include "ecma/utils/messages.h"

using namespace ecma;
using namespace ecma::lex;

void UnknownTokenException::printMessage()
{
    std::ostringstream ss;

    ss << "Unknown token: " << m_token;

    uint length = m_token.length();
    utils::Messages::ReportError(ss.str(), m_pos, length > 0 ? length - 1 : 0);
}
