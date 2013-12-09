#ifndef ECMA_PARSER_PARSER_H_
#define ECMA_PARSER_PARSER_H_

#include "ecma/lex/lexer.h"

namespace ecma
{
    namespace parser
    {
        class Parser
        {
        public:
            Parser(lex::Lexer &lexer);
            ~Parser();
        };
    }
}

#endif /* ECMA_PARSER_PARSER_H_ */
