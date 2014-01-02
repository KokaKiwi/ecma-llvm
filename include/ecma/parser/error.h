#ifndef ECMA_PARSER_ERROR_H_
#define ECMA_PARSER_ERROR_H_

#include <string>
#include "ecma/lex/token.h"

namespace ecma
{
    namespace parser
    {
        class ParsingError
        {
        public:
            inline ParsingError(const std::string &message, lex::Token *token)
                : m_message(message)
                , m_token(token)
            {}

            inline lex::Token *token() const
            {
                return m_token;
            }

            inline const std::string message() const
            {
                return m_message;
            }

        private:
            std::string m_message;
            lex::Token *m_token;
        };
    }
}

#endif /* ECMA_PARSER_ERROR_H_ */
