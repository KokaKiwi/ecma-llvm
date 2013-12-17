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
            inline UnexpectedToken(lex::Token *token)
                : m_token(token)
            {}
            inline ~UnexpectedToken() throw()
            {
                delete m_token;
            }

            inline lex::Token *token()
            {
                return m_token;
            }

            void printMessage();

        private:
            lex::Token *m_token;
        };
    }
}

#endif /* ECMA_PARSER_EXCEPTION_H_ */
