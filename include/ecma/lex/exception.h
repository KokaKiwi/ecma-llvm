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
            typedef std::pair<uint, uint> Position;

            inline UnknownTokenException(const std::string &token, const Position &pos)
                : m_token(token)
                , m_pos(pos)
            {}

            inline const std::string &token() const
            {
                return m_token;
            }

            inline const Position &pos() const
            {
                return m_pos;
            }

            void printMessage();

        private:
            std::string m_token;
            Position m_pos;
        };
    }
}

#endif /* ECMA_LEX_EXCEPTION_H_ */
