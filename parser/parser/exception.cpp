#include <sstream>
#include "ecma/parser/exception.h"
#include "ecma/utils/messages.h"

using namespace ecma;
using namespace ecma::parser;

void UnexpectedToken::printMessage()
{
    std::ostringstream ss;

    ss << "Unexpected token: " << m_token->toString();

    uint length = m_token->text().length();
    utils::Messages::ReportError(ss.str(), m_token->pos(), length > 0 ? length - 1 : 0);
}
