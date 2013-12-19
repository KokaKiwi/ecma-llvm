#ifndef ECMA_LEX_TOKEN_H_
#define ECMA_LEX_TOKEN_H_

#include <string>
#include <utility>
#include <iostream>
#include <sstream>
#include "lemon-parser.h"

namespace ecma
{
    namespace lex
    {
        class Token
        {
        public:
            typedef std::pair<uint, uint> Position;

            enum class AutoType;
            enum class Type;

            inline Token(Type type, const std::string &text, const Position &pos)
                : m_type(type)
                , m_text(text)
                , m_pos(pos)
            {}

            inline ~Token() {}

            inline const Type type() const
            {
                return m_type;
            }

            inline const std::string &text() const
            {
                return m_text;
            }

            inline uint length() const
            {
                return m_text.length();
            }

            inline const Position &pos() const
            {
                return m_pos;
            }

            inline operator std::string() const
            {
                return text();
            }

            inline operator const char *() const
            {
                return text().c_str();
            }

            inline operator int() const
            {
                return std::stoi(text());
            }

            inline operator long() const
            {
                return std::stol(text());
            }

            inline operator double() const
            {
                return std::stod(text());
            }

            inline operator float() const
            {
                return std::stof(text());
            }

            template<typename T>
            inline T as() const
            {
                T value;

                std::istringstream ss(text());
                ss >> value;

                return value;
            }

            static const std::string typeString(Type type);

            inline const std::string toString() const
            {
                return typeString(m_type);
            }

        private:
            Type m_type;
            std::string m_text;
            Position m_pos;
        };

        enum class Token::AutoType
        {
            #define ECMA_TOKEN_DEFINE(name, value, repr)
            #define ECMA_TOKEN_AUTO(name, repr) name,
            #define ECMA_TOKEN(name, repr)

            #include "ecma/lex/types.h"

            #undef ECMA_TOKEN_DEFINE
            #undef ECMA_TOKEN_AUTO
            #undef ECMA_TOKEN
        };

        enum class Token::Type
        {
            #define ECMA_TOKEN_DEFINE(name, value, repr) name = value,
            #define ECMA_TOKEN_AUTO(name, repr)
            #define ECMA_TOKEN(name, repr) ECMA_TOKEN_DEFINE(name, ECMA_TOKEN_TYPE_##name, repr)

            #include "ecma/lex/types.h"

            #undef ECMA_TOKEN_DEFINE
            #undef ECMA_TOKEN_AUTO
            #undef ECMA_TOKEN

            #define ECMA_TOKEN_DEFINE(name, value, repr)
            #define ECMA_TOKEN_AUTO(name, repr) name = -(static_cast<int>(Token::AutoType::name) + 1),
            #define ECMA_TOKEN(name, repr)

            #include "ecma/lex/types.h"

            #undef ECMA_TOKEN_DEFINE
            #undef ECMA_TOKEN_AUTO
            #undef ECMA_TOKEN
        };

        template<>
        inline std::string Token::as<std::string>() const
        {
            return text();
        }

        inline std::ostream &operator<<(std::ostream &os, const Token &token)
        {
            os << token.toString() << "(\"" << token.text() << "\")";

            return os;
        }
    }
}

#endif /* ECMA_LEX_TOKEN_H_ */
