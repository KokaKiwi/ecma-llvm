#ifndef ECMA_LEX_LEXER_H_
#define ECMA_LEX_LEXER_H_

#include <string>
#include "ecma/lex/token.h"

namespace ecma
{
    namespace lex
    {
        class Lexer
        {
        public:
            Lexer(const char *source, uint length);
            Lexer(const std::string &source);
            ~Lexer();

            Token *consume();

        private:
            const char *m_source;
            const char *m_source_end;
            const char *m_source_eof;
            const char *m_ts;
            const char *m_te;
            int m_current_state;
            int m_act;

            Token::Position m_pos;
        };
    }
}

#endif /* ECMA_LEX_LEXER_H_ */
