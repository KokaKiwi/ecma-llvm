#ifndef ECMA_PARSER_PARSER_H_
#define ECMA_PARSER_PARSER_H_

#include <stddef.h>
#include <vector>
#include <string>
#include <memory>
#include "ecma/lex/lexer.h"
#include "ecma/lex/lexeme.h"
#include "ecma/ast/stmt/block.h"

namespace ecma
{
    namespace parser
    {
        class Parser
        {
        public:
            Parser(lex::Lexer &lexer);
            ~Parser();

            void exec(void);

            inline std::vector<std::string> &errors(void)
            {
                return m_errors;
            }

            inline ast::stmt::Block *program(void) const
            {
                return m_program;
            }
            inline Parser &program(ast::stmt::Block *program)
            {
                m_program = program;
                return *this;
            }

            inline const bool debug(void) const
            {
                return m_debug;
            }
            inline Parser &debug(bool debug)
            {
                m_debug = debug;
                return *this;
            }

            inline lex::Lexeme *lexeme(void) const
            {
                return m_lexeme.get();
            }
            inline Parser &lexeme(lex::Lexeme * lexeme)
            {
                m_lexeme.reset(lexeme);
                return *this;
            }
            inline lex::Lexeme *takeLexeme(void)
            {
                return m_lexeme.release();
            }

        private:
            void *m_yyp;
            lex::Lexer &m_lexer;
            bool m_debug;
            std::vector<std::string> m_errors;
            ast::stmt::Block *m_program;
            std::unique_ptr<lex::Lexeme> m_lexeme;
        };
    }
}

void *EcmaParseAlloc(void *(*mallocProc)(size_t));
void EcmaParseFree(void *p, void (*freeProc)(void*));
void EcmaParse(void *yyp, int yymajor, ecma::lex::Lexeme *yyminor, ecma::parser::Parser *parser);
void EcmaParseTrace(FILE *stream, char *prefix);

#endif /* ECMA_PARSER_PARSER_H_ */
