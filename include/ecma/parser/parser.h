#ifndef ECMA_PARSER_PARSER_H_
#define ECMA_PARSER_PARSER_H_

#include <stddef.h>
#include <vector>
#include <string>
#include "ecma/lex/lexer.h"
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

            inline bool error(void) const
            {
                return m_error;
            }
            inline Parser &error(bool error)
            {
                m_error = error;
                return *this;
            }

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

        private:
            void *m_yyp;
            lex::Lexer &m_lexer;
            bool m_error;
            std::vector<std::string> m_errors;
            ast::stmt::Block *m_program;
        };
    }
}

void *EcmaParseAlloc(void *(*mallocProc)(size_t));
void EcmaParseFree(void *p, void (*freeProc)(void*));
void EcmaParse(void *yyp, int yymajor, ecma::lex::Lexeme *yyminor, ecma::parser::Parser *parser);

#endif /* ECMA_PARSER_PARSER_H_ */
