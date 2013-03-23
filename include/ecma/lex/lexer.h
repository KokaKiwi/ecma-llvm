#ifndef ECMA_LEX_LEXER_H_
#define ECMA_LEX_LEXER_H_

#include <utility>
#include "ecma/lex/lexeme.h"

namespace ecma
{
    namespace lex
    {
        class Lexer
        {
        public:
            Lexer(const char *source, unsigned int length);
            Lexer(const std::string &source);
            ~Lexer();

            lex::Lexeme *consume(void);

        private:
            const char *m_source;
            const char *m_source_end;
            const char *m_source_eof;
            const char *m_ts;
            const char *m_te;
            int m_current_state;
            int m_act;

            Lexeme::pos_t m_position;
        };
    }
}

#endif /* ECMA_LEX_LEXER_H_ */
