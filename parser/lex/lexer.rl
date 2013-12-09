#include <string>
#include <utility>
#include "ecma/lex/lexer.h"
#include "ecma/lex/token.h"

%% machine ecma_lexer;
%% write data;

%% variable p   m_source;
%% variable pe  m_source_end;
%% variable eof m_source_eof;
%% variable ts  m_ts;
%% variable te  m_te;
%% variable cs  m_current_state;
%% variable act m_act;

using namespace ecma;
using namespace ecma::lex;

#define ECMA_TOKEN(name)    Token::Type::name

Lexer::Lexer(const char *source, uint length)
    : m_source(source)
    , m_source_end(source + length)
    , m_source_eof(m_source_end)
    , m_ts(nullptr)
    , m_te(nullptr)
    , m_current_state(0)
    , m_act(0)
    , m_pos(std::make_pair(1, 1))
{
    %% write init;
}

Lexer::Lexer(const std::string &source)
    : Lexer(source.c_str(), source.length())
{
}

Lexer::~Lexer()
{
}

Token *Lexer::consume()
{
    %%{
        spaces                      =   (' '|'\t')+;
        newline                     =   ('\n'|'\r\n');

        main := |*
            # keywords
            "var"                   =>  { type = ECMA_TOKEN(VAR); fbreak; };

            # symbols
            ";"                     =>  { type = ECMA_TOKEN(SEMICOLON); fbreak; };

            # values
            [a-zA-Z_][a-zA-Z0-9_]*  =>  { type = ECMA_TOKEN(IDENT); fbreak; };

            spaces                  =>  { type = ECMA_TOKEN(SPACES); fbreak; };
            newline                 =>  { type = ECMA_TOKEN(NEWLINE); fbreak; };

            any                     =>  { type = ECMA_TOKEN(UNKNOWN); fbreak; };
        *|;
    }%%

    Token::Type type;

    if (m_source == m_source_end)
    {
        m_ts = m_te = m_source;
        type = ECMA_TOKEN(END);
    }
    else
    {
        %% write exec;
    }

    uint size = m_te - m_ts;
    Token::Position pos = m_pos;

    return new Token(type, std::string(m_ts, size), pos);
}