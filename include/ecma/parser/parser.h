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
            Parser();
            ~Parser();

            void parse(lex::Lexer &lexer);

            inline bool debug() const
            {
                return m_debug;
            }
            inline Parser &debug(bool debug)
            {
                m_debug = debug;
                return *this;
            }

        private:
            void *m_yyp;

            bool m_debug;
        };
    }
}

void *ecma_parseAlloc(void *(*mallocProc)(size_t));
void ecma_parseFree(void *p, void (*freeProc)(void*));
void ecma_parse(void *yyp, int yymajor, ecma::lex::Token *yyminor, ecma::parser::Parser *parser);
void ecma_parseTrace(FILE *stream, char *prefix);

#endif /* ECMA_PARSER_PARSER_H_ */
