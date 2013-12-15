#ifndef ECMA_UTILS_ELEMENT_H_
#define ECMA_UTILS_ELEMENT_H_

#include "ecma/lex/token.h"

namespace ecma
{
    namespace utils
    {
        class Element
        {
        public:
            typedef std::pair<uint, uint> Position;

            inline Element()
                : m_pos(0, 0)
                , m_length(0)
            {}

            inline const Position &pos() const
            {
                return m_pos;
            }

            inline uint length() const
            {
                return m_length;
            }

            inline Element &element(const Position &pos, uint length)
            {
                m_pos = pos;
                m_length = length;
                return *this;
            }

            inline Element &element(const lex::Token *tok)
            {
                return element(tok->pos(), tok->text().length());
            }

            inline Element &element(const lex::Token *begin, const lex::Token *end)
            {
                Position first = begin->pos();
                Position last = end->pos();
                uint length = last.first - first.first + end->text().length();
                return element(first, length);
            }

        private:
            Position m_pos;
            uint m_length;
        };
    }
}

#endif /* ECMA_UTILS_ELEMENT_H_ */
