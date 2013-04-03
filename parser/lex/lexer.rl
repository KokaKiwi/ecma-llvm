#include <stddef.h>
#include <string>
#include <utility>
#include "ecma/lex/lexer.h"
#include "ecma/lex/lexeme.h"

%% machine EcmaLexer;
%% write data;

using namespace ecma::lex;

Lexer::Lexer(const char *source, unsigned int length)
    : m_source(source)
    , m_source_end(source + length)
    , m_source_eof(m_source_end)
    , m_ts(nullptr), m_te(nullptr)
    , m_current_state(0), m_act(0)
    , m_position(std::make_pair(1, 1))
{

}

Lexer::Lexer(const std::string &source): Lexer(source.c_str(), source.length())
{

}

Lexer::~Lexer()
{

}

Lexeme *Lexer::consume(void)
{
    %%{
        identifier          = [a-zA-Z$_][a-zA-Z0-9$_]*;
        number              = [0-9]+;
        string              = ('"'([^"]|'\\' any)*'"'|'\''([^']|'\\' any)*'\'');

        spaces              = (' '|'\t')+;
        newline             = ('\n');

        linecomment         = '//'[^\n]*;

        main := |*
            'do'            => { type = Lexeme::Type::Do; fbreak; };
            'if'            => { type = Lexeme::Type::If; fbreak; };
            'in'            => { type = Lexeme::Type::In; fbreak; };
            'for'           => { type = Lexeme::Type::For; fbreak; };
            'new'           => { type = Lexeme::Type::New; fbreak; };
            'try'           => { type = Lexeme::Type::Try; fbreak; };
            'var'           => { type = Lexeme::Type::Var; fbreak; };
            'case'          => { type = Lexeme::Type::Case; fbreak; };
            'else'          => { type = Lexeme::Type::Else; fbreak; };
            'null'          => { type = Lexeme::Type::Null; fbreak; };
            'this'          => { type = Lexeme::Type::This; fbreak; };
            'true'          => { type = Lexeme::Type::True; fbreak; };
            'with'          => { type = Lexeme::Type::With; fbreak; };
            'break'         => { type = Lexeme::Type::Break; fbreak; };
            'catch'         => { type = Lexeme::Type::Catch; fbreak; };
            'false'         => { type = Lexeme::Type::False; fbreak; };
            'while'         => { type = Lexeme::Type::While; fbreak; };
            'return'        => { type = Lexeme::Type::Return; fbreak; };
            'switch'        => { type = Lexeme::Type::Switch; fbreak; };
            'default'       => { type = Lexeme::Type::Default; fbreak; };
            'finally'       => { type = Lexeme::Type::Finally; fbreak; };
            'continue'      => { type = Lexeme::Type::Continue; fbreak; };
            'function'      => { type = Lexeme::Type::Function; fbreak; };
            'undefined'     => { type = Lexeme::Type::Undefined; fbreak; };
            'instanceof'    => { type = Lexeme::Type::InstanceOf; fbreak; };

            '+'             => { type = Lexeme::Type::Plus; fbreak; };
            '-'             => { type = Lexeme::Type::Minus; fbreak; };
            '*'             => { type = Lexeme::Type::Mul; fbreak; };
            '/'             => { type = Lexeme::Type::Div; fbreak; };
            '%'             => { type = Lexeme::Type::Mod; fbreak; };

            '='             => { type = Lexeme::Type::Assign; fbreak; };
            '+='            => { type = Lexeme::Type::PlusAssign; fbreak; };
            '-='            => { type = Lexeme::Type::MinusAssign; fbreak; };
            '*='            => { type = Lexeme::Type::MulAssign; fbreak; };
            '/='            => { type = Lexeme::Type::DivAssign; fbreak; };
            '%='            => { type = Lexeme::Type::ModAssign; fbreak; };

            '>>='           => { type = Lexeme::Type::RightShiftAssign; fbreak; };
            '&='            => { type = Lexeme::Type::BinaryAndAssign; fbreak; };
            '|='            => { type = Lexeme::Type::BinaryOrAssign; fbreak; };
            '^='            => { type = Lexeme::Type::XorAssign; fbreak; };

            '>'             => { type = Lexeme::Type::Greater; fbreak; };
            '>='            => { type = Lexeme::Type::GreaterOrEqual; fbreak; };
            '<'             => { type = Lexeme::Type::Lesser; fbreak; };
            '<='            => { type = Lexeme::Type::LesserOrEqual; fbreak; };
            '=='            => { type = Lexeme::Type::Equal; fbreak; };
            '!='            => { type = Lexeme::Type::NotEqual; fbreak; };

            '!'             => { type = Lexeme::Type::Not; fbreak; };
            '~'             => { type = Lexeme::Type::Inv; fbreak; };
            '++'            => { type = Lexeme::Type::Incrementation; fbreak; };
            '--'            => { type = Lexeme::Type::Decrementation; fbreak; };

            '||'            => { type = Lexeme::Type::LogicalOr; fbreak; };
            '&&'            => { type = Lexeme::Type::LogicalAnd; fbreak; };
            '|'             => { type = Lexeme::Type::BitwiseOr; fbreak; };
            '&'             => { type = Lexeme::Type::BitwiseAnd; fbreak; };
            '^'             => { type = Lexeme::Type::BitwiseXor; fbreak; };

            '<<'            => { type = Lexeme::Type::LeftShift; fbreak; };
            '>>'            => { type = Lexeme::Type::RightShift; fbreak; };

            '('             => { type = Lexeme::Type::LParen; fbreak; };
            ')'             => { type = Lexeme::Type::RParen; fbreak; };
            '['             => { type = Lexeme::Type::LBracket; fbreak; };
            ']'             => { type = Lexeme::Type::RBracket; fbreak; };
            '{'             => { type = Lexeme::Type::LBrace; fbreak; };
            '}'             => { type = Lexeme::Type::RBrace; fbreak; };

            '?'             => { type = Lexeme::Type::QuestionMark; fbreak; };
            '.'             => { type = Lexeme::Type::Dot; fbreak; };

            ';'             => { type = Lexeme::Type::Semicolon; fbreak; };
            ':'             => { type = Lexeme::Type::Colon; fbreak; };
            ','             => { type = Lexeme::Type::Comma; fbreak; };

            identifier      => { type = Lexeme::Type::Identifier; fbreak; };
            number          => { type = Lexeme::Type::Number; fbreak; };
            string          => { type = Lexeme::Type::String; fbreak; };

            spaces          => { type = Lexeme::Type::Spaces; fbreak; };
            newline         => { type = Lexeme::Type::Newline; fbreak; };

            linecomment     => { fbreak; };
            any             => { fbreak; };
        *|;
    }%%

    Lexeme::Type type;

    if (m_source == m_source_end)
    {
        m_ts = m_te = m_source;
        type = Lexeme::Type::End;
    }
    else
    {
        %% variable cs  m_current_state;
        %% variable p   m_source;
        %% variable pe  m_source_end;
        %% variable eof m_source_eof;
        %% variable ts  m_ts;
        %% variable te  m_te;
        %% variable act m_act;

        %% write init;
        %% write exec;
    }

    unsigned int size = m_te - m_ts;
    Lexeme::pos_t position = m_position;

    if (type == Lexeme::Type::Newline)
    {
        m_position.first += 1;
        m_position.second = size;
    }
    else
    {
        m_position.second += size;
    }

    return new Lexeme(type, std::string(m_ts, size), position);
}
