#include "ecma/lex/lexeme.h"

using namespace ecma::lex;

const char *Lexeme::typeString(Lexeme::Type type)
{
    switch (type)
    {
        #define ECMA_LEXEME_NAME(name) #name
        #define ECMA_LEXEME(name) case Lexeme::Type::name: return ECMA_LEXEME_NAME(name);
        #define ECMA_AUTO_LEXEME(name) ECMA_LEXEME(name)
        #define ECMA_DEFINE_LEXEME(name, value) ECMA_LEXEME(name)

        #include "ecma/lex/types.h"

        #undef ECMA_LEXEME_NAME
        #undef ECMA_LEXEME
        #undef ECMA_AUTO_LEXEME
        #undef ECMA_DEFINE_LEXEME
    }
    return nullptr;
}
