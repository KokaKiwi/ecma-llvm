#include "ecma/lex/token.h"

using namespace ecma;
using namespace ecma::lex;

const std::string Token::typeString(Token::Type type)
{
    switch (type)
    {
        #define ECMA_TOKEN_NAME(name) #name
        #define ECMA_TOKEN_CASE(name)   \
            case Token::Type::name:     \
                return ECMA_TOKEN_NAME(name);
        #define ECMA_TOKEN_DEFINE(name, value) ECMA_TOKEN_CASE(name)
        #define ECMA_TOKEN_AUTO(name) ECMA_TOKEN_CASE(name)
        #define ECMA_TOKEN(name) ECMA_TOKEN_CASE(name)

        #include "ecma/lex/types.h"

        #undef ECMA_TOKEN_NAME
        #undef ECMA_TOKEN_CASE
        #undef ECMA_TOKEN_DEFINE
        #undef ECMA_TOKEN_AUTO
        #undef ECMA_TOKEN
    }
    return "Unknown";
}
