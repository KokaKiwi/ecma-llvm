#ifndef ECMA_LEX_EXCEPTION_H_
#define ECMA_LEX_EXCEPTION_H_

#include <exception>
#include <string>
#include <sstream>

namespace ecma
{
    namespace lex
    {
        class UnknownTokenException: public std::exception
        {
        public:
            inline UnknownTokenException(const std::string &token)
                : m_token(token)
            {}

            inline const std::string &token() const
            {
                return m_token;
            }

        private:
            std::string m_token;
        };
    }
}

#endif /* ECMA_LEX_EXCEPTION_H_ */
