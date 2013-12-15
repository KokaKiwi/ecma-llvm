#include <iostream>
#include <string>
#include <utility>
#include "ecma/lex/lexer.h"
#include "ecma/lex/token.h"
#include "ecma/lex/exception.h"

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
        # Comment
        single_comment              =   '//' [^\n]* '\n';
        multi_comment               =   '/*' any* :>> '*/';

        comment                     =   (single_comment | multi_comment);

        # Identifier
        ident_start                 =   (alpha | '$' | '_');
        ident_part                  =   (ident_start | digit);

        ident                       =   ident_start ident_part*;

        # Number literal
        integer                     =   [0-9]+;
        exponent                    =   ('e'|'E') integer;
        decimal                     =   (
                integer ('.' (integer)? (exponent)?)?
            |   '.' integer (exponent)?
        );
        signed                      =   ('+'|'-')* decimal;

        hex_base                    =   [0-9a-fA-F]+;
        hex                         =   ('0x'|'0X') hex_base;

        number                      =   (signed | hex);

        # String literal
        escape_char                 =   ('"'|'\''|'\\'|ascii - ([0-9]|'x'|'u'));
        escape_int                  =   integer;
        escape_hex                  =   'x' hex_base;
        escape_unicode              =   'u' integer;

        escape                      =   '\\' (escape_char | escape_int | escape_hex | escape_unicode);

        double_str_char             =   (any - ('"'|'\\') | escape);
        single_str_char             =   (any - ('\''|'\\') | escape);

        string                      =   ('"' double_str_char* '"' | '\'' single_str_char* '\'');

        # Regexp
        regexp_non_term             =   any - ('\n');

        regexp_escape               =   '\\' regexp_non_term;

        regexp_class_char           =   (regexp_non_term - (']'|'\\') | regexp_escape);
        regexp_class                =   '[' regexp_class_char* ']';

        regexp_body_char            =   (regexp_escape | regexp_class);

        regexp_body_first           =   (regexp_non_term - ('*'|'\\'|'/'|'[') | regexp_body_char);
        regexp_body_chars           =   (regexp_non_term - ('\\'|'/'|'[') | regexp_body_char);
        regexp_body                 =   regexp_body_first regexp_body_chars*;

        regexp_flags                =   ident_part+;

        regexp                      =   '/' regexp_body? '/' regexp_flags?;

        # Misc symbols
        spaces                      =   (' '|'\t')+;
        newline                     =   ('\n'|'\r\n');

        main := |*
            {{ smart_indent(lexer, 12) }}
            regexp                  =>  { type = ECMA_TOKEN(REGEXP); fbreak; };
            string                  =>  { type = ECMA_TOKEN(STRING); fbreak; };
            number                  =>  { type = ECMA_TOKEN(NUMBER); fbreak; };
            ident                   =>  { type = ECMA_TOKEN(IDENT); fbreak; };

            spaces                  =>  { type = ECMA_TOKEN(SPACES); fbreak; };
            newline                 =>  { type = ECMA_TOKEN(NEWLINE); fbreak; };

            comment                 =>  { type = ECMA_TOKEN(COMMENT); fbreak; };

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

    std::string str(m_ts, size);

    if (type == ECMA_TOKEN(UNKNOWN))
    {
        throw UnknownTokenException(str, pos);
    }

    for (uint i = 0; i < size; i++)
    {
        char c = m_ts[i];
        if (c == '\n')
        {
            m_pos.first++;
            m_pos.second = 1;
        }
        else
        {
            m_pos.second++;
        }
    }

    Token *token = new Token(type, str, pos);
    return token;
}
