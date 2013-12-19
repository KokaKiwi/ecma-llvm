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
            inline ParsingError(const std::string &fmt, lex::Token *token)
                : m_fmt(fmt)
                , m_token(token)
            {}

            inline lex::Token *token() const
            {
                return m_token;
            }

            const std::string message() const;

        private:
            std::string m_fmt;
            lex::Token *m_token;
        };
    }
}

#endif /* ECMA_PARSER_ERROR_H_ */
