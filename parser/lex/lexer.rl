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
            # keywords
            "instanceof"            =>  { type = ECMA_TOKEN(INSTANCEOF); fbreak; };
            "continue"              =>  { type = ECMA_TOKEN(CONTINUE); fbreak; };
            "debugger"              =>  { type = ECMA_TOKEN(DEBUGGER); fbreak; };
            "function"              =>  { type = ECMA_TOKEN(FUNCTION); fbreak; };
            "default"               =>  { type = ECMA_TOKEN(DEFAULT); fbreak; };
            "finally"               =>  { type = ECMA_TOKEN(FINALLY); fbreak; };
            "delete"                =>  { type = ECMA_TOKEN(DELETE); fbreak; };
            "return"                =>  { type = ECMA_TOKEN(RETURN); fbreak; };
            "switch"                =>  { type = ECMA_TOKEN(SWITCH); fbreak; };
            "typeof"                =>  { type = ECMA_TOKEN(TYPEOF); fbreak; };
            "break"                 =>  { type = ECMA_TOKEN(BREAK); fbreak; };
            "catch"                 =>  { type = ECMA_TOKEN(CATCH); fbreak; };
            "throw"                 =>  { type = ECMA_TOKEN(THROW); fbreak; };
            "while"                 =>  { type = ECMA_TOKEN(WHILE); fbreak; };
            "case"                  =>  { type = ECMA_TOKEN(CASE); fbreak; };
            "else"                  =>  { type = ECMA_TOKEN(ELSE); fbreak; };
            "this"                  =>  { type = ECMA_TOKEN(THIS); fbreak; };
            "void"                  =>  { type = ECMA_TOKEN(VOID); fbreak; };
            "with"                  =>  { type = ECMA_TOKEN(WITH); fbreak; };
            "for"                   =>  { type = ECMA_TOKEN(FOR); fbreak; };
            "get"                   =>  { type = ECMA_TOKEN(GET); fbreak; };
            "new"                   =>  { type = ECMA_TOKEN(NEW); fbreak; };
            "set"                   =>  { type = ECMA_TOKEN(SET); fbreak; };
            "try"                   =>  { type = ECMA_TOKEN(TRY); fbreak; };
            "var"                   =>  { type = ECMA_TOKEN(VAR); fbreak; };
            "do"                    =>  { type = ECMA_TOKEN(DO); fbreak; };
            "if"                    =>  { type = ECMA_TOKEN(IF); fbreak; };
            "in"                    =>  { type = ECMA_TOKEN(IN); fbreak; };

            # future keywords
            "extends"               =>  { type = ECMA_TOKEN(EXTENDS); fbreak; };
            "export"                =>  { type = ECMA_TOKEN(EXPORT); fbreak; };
            "import"                =>  { type = ECMA_TOKEN(IMPORT); fbreak; };
            "class"                 =>  { type = ECMA_TOKEN(CLASS); fbreak; };
            "const"                 =>  { type = ECMA_TOKEN(CONST); fbreak; };
            "super"                 =>  { type = ECMA_TOKEN(SUPER); fbreak; };
            "enum"                  =>  { type = ECMA_TOKEN(ENUM); fbreak; };

            # future keywords (strict)
            "implements"            =>  { type = ECMA_TOKEN(IMPLEMENTS); fbreak; };
            "interface"             =>  { type = ECMA_TOKEN(INTERFACE); fbreak; };
            "protected"             =>  { type = ECMA_TOKEN(PROTECTED); fbreak; };
            "package"               =>  { type = ECMA_TOKEN(PACKAGE); fbreak; };
            "private"               =>  { type = ECMA_TOKEN(PRIVATE); fbreak; };
            "public"                =>  { type = ECMA_TOKEN(PUBLIC); fbreak; };
            "static"                =>  { type = ECMA_TOKEN(STATIC); fbreak; };
            "yield"                 =>  { type = ECMA_TOKEN(YIELD); fbreak; };
            "let"                   =>  { type = ECMA_TOKEN(LET); fbreak; };

            # symbols
            ">>>="                  =>  { type = ECMA_TOKEN(ZERO_RIGHT_SHIFT_ASSIGN); fbreak; };
            "==="                   =>  { type = ECMA_TOKEN(STRICT_EQUAL); fbreak; };
            "!=="                   =>  { type = ECMA_TOKEN(STRICT_NOT_EQUAL); fbreak; };
            ">>>"                   =>  { type = ECMA_TOKEN(ZERO_RIGHT_SHIFT); fbreak; };
            "<<="                   =>  { type = ECMA_TOKEN(LEFT_SHIFT_ASSIGN); fbreak; };
            ">>="                   =>  { type = ECMA_TOKEN(RIGHT_SHIFT_ASSIGN); fbreak; };
            "<="                    =>  { type = ECMA_TOKEN(LESSER_EQ); fbreak; };
            ">="                    =>  { type = ECMA_TOKEN(GREATER_EQ); fbreak; };
            "=="                    =>  { type = ECMA_TOKEN(EQUAL); fbreak; };
            "!="                    =>  { type = ECMA_TOKEN(NOT_EQUAL); fbreak; };
            "++"                    =>  { type = ECMA_TOKEN(INCREMENT); fbreak; };
            "--"                    =>  { type = ECMA_TOKEN(DECREMENT); fbreak; };
            "<<"                    =>  { type = ECMA_TOKEN(LEFT_SHIFT); fbreak; };
            ">>"                    =>  { type = ECMA_TOKEN(RIGHT_SHIFT); fbreak; };
            "&&"                    =>  { type = ECMA_TOKEN(LOGIC_AND); fbreak; };
            "||"                    =>  { type = ECMA_TOKEN(LOGIC_OR); fbreak; };
            "+="                    =>  { type = ECMA_TOKEN(PLUS_ASSIGN); fbreak; };
            "-="                    =>  { type = ECMA_TOKEN(MINUS_ASSIGN); fbreak; };
            "*="                    =>  { type = ECMA_TOKEN(MUL_ASSIGN); fbreak; };
            "%="                    =>  { type = ECMA_TOKEN(MOD_ASSIGN); fbreak; };
            "/="                    =>  { type = ECMA_TOKEN(DIV_ASSIGN); fbreak; };
            "&="                    =>  { type = ECMA_TOKEN(BITWISE_AND_ASSIGN); fbreak; };
            "|="                    =>  { type = ECMA_TOKEN(BITWISE_OR_ASSIGN); fbreak; };
            "^="                    =>  { type = ECMA_TOKEN(BITWISE_XOR_ASSIGN); fbreak; };
            "{"                     =>  { type = ECMA_TOKEN(LBRACE); fbreak; };
            "}"                     =>  { type = ECMA_TOKEN(RBRACE); fbreak; };
            "("                     =>  { type = ECMA_TOKEN(LPAREN); fbreak; };
            ")"                     =>  { type = ECMA_TOKEN(RPAREN); fbreak; };
            "["                     =>  { type = ECMA_TOKEN(LBRACKET); fbreak; };
            "]"                     =>  { type = ECMA_TOKEN(RBRACKET); fbreak; };
            "."                     =>  { type = ECMA_TOKEN(DOT); fbreak; };
            ";"                     =>  { type = ECMA_TOKEN(SEMICOLON); fbreak; };
            ","                     =>  { type = ECMA_TOKEN(COMMA); fbreak; };
            "?"                     =>  { type = ECMA_TOKEN(QUESTION); fbreak; };
            ":"                     =>  { type = ECMA_TOKEN(COLON); fbreak; };
            "<"                     =>  { type = ECMA_TOKEN(LESSER); fbreak; };
            ">"                     =>  { type = ECMA_TOKEN(GREATER); fbreak; };
            "+"                     =>  { type = ECMA_TOKEN(PLUS); fbreak; };
            "-"                     =>  { type = ECMA_TOKEN(MINUS); fbreak; };
            "*"                     =>  { type = ECMA_TOKEN(MUL); fbreak; };
            "%"                     =>  { type = ECMA_TOKEN(MOD); fbreak; };
            "/"                     =>  { type = ECMA_TOKEN(DIV); fbreak; };
            "&"                     =>  { type = ECMA_TOKEN(BITWISE_AND); fbreak; };
            "|"                     =>  { type = ECMA_TOKEN(BITWISE_OR); fbreak; };
            "^"                     =>  { type = ECMA_TOKEN(BITWISE_XOR); fbreak; };
            "="                     =>  { type = ECMA_TOKEN(ASSIGN); fbreak; };
            "!"                     =>  { type = ECMA_TOKEN(NOT); fbreak; };
            "~"                     =>  { type = ECMA_TOKEN(INV); fbreak; };

            # literal
            "false"                 =>  { type = ECMA_TOKEN(LIT_FALSE); fbreak; };
            "null"                  =>  { type = ECMA_TOKEN(LIT_NULL); fbreak; };
            "true"                  =>  { type = ECMA_TOKEN(LIT_TRUE); fbreak; };

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