#ifndef ECMA_PARSER_EXCEPTION_H_
#define ECMA_PARSER_EXCEPTION_H_

#include <exception>
#include <vector>
#include <string>

#include "ecma/lex/lexeme.h"

namespace ecma
{
    namespace parser
    {
        class Exception: public std::exception
        {
        public:
            Exception(const std::string &message, const lex::Lexeme &lexeme, const std::vector<std::string> &expected_tokens);
            inline virtual ~Exception(void) throw() {}

            inline const std::string &message(void) const throw()
            {
                return m_message;
            }

            inline const lex::Lexeme &lexeme(void) const throw()
            {
                return m_lexeme;
            }

            inline const std::vector<std::string> &expected_tokens(void) const throw()
            {
                return m_expected_tokens;
            }

            inline virtual const char *what(void) const throw()
            {
                return m_what.c_str();
            }

        private:
            std::string m_message;
            lex::Lexeme m_lexeme;
            std::vector<std::string> m_expected_tokens;

            std::string m_what;
        };
    }
}

#endif /* ECMA_PARSER_EXCEPTION_H_ */
