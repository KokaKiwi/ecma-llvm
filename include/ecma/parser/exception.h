#ifndef ECMA_PARSER_EXCEPTION_H_
#define ECMA_PARSER_EXCEPTION_H_

#include <exception>
#include <vector>
#include <string>
#include <memory>
#include "ecma/lex/token.h"

namespace ecma
{
    namespace parser
    {
        class UnexpectedToken: public std::exception
        {
        public:
            inline UnexpectedToken(lex::Token *token, const std::vector<std::string> &expected)
                : m_token(token)
                , m_expected(expected)
            {}
            inline ~UnexpectedToken() throw()
            {
                delete m_token;
            }

            inline lex::Token *token()
            {
                return m_token;
            }

            inline const std::vector<std::string> &expected() const
            {
                return m_expected;
            }

            void printMessage();

        private:
            lex::Token *m_token;
            std::vector<std::string> m_expected;
        };
    }
}

#endif /* ECMA_PARSER_EXCEPTION_H_ */
