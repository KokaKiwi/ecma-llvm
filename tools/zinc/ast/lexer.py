import ply.lex as lex

tokens = (
    # Literals
    'IDENT',

    'NONE',
    'NUMBER',
    'STRING',
    'REGEX',
    'BOOLEAN',

    # Keywords
    'ASSIGN',
    'FAT_ARROW',

    'RAW',
)

states = (
    ('raw', 'exclusive'),
)

literals = '=#,:;.()[]/*-+%!|'

t_IDENT             = r'[\-_\w]+'

t_ASSIGN            = r'::='
t_FAT_ARROW         = r'=>'

t_ignore            = ' \t\n'
t_ignore_COMMENT    = '//[^\n]*\n'

t_raw_ignore        = t_ignore

def t_NUMBER(t):
    r'(\+|\-)?[0-9]+'
    t.value = int(t.value)
    return t

def t_STRING(t):
    r'(\'[^\']*\'|\"[^\"]*\")'
    t.value = t.value[1:-1]
    t.lexer.lineno += t.value.count('\n')
    return t

def t_REGEX(t):
    r'r(\'[^\']*\'|\"[^\"]*\")'
    t.value = t.value[2:-1]
    t.lexer.lineno += t.value.count('\n')
    return t

def t_NONE(t):
    r'(null|nullptr|[Nn]one)'
    t.value = None
    return t

def t_BOOLEAN(t):
    r'([Tt][Rr][Uu][Ee]|[Ff][Aa][Ll][Ss][Ee]|[Yy][Ee][Ss]|[Nn][Oo])'
    if t.value in ('true', 'yes'):
        t.value = True
    else:
        t.value = False
    return t

def t_raw(t):
    r'\{'
    t.lexer.code_start = t.lexer.lexpos
    t.lexer.level = 1
    t.lexer.push_state('raw')

def t_raw_lbrace(t):
    r'\{'
    t.lexer.level += 1

def t_raw_rbrace(t):
    r'\}'
    t.lexer.level -= 1

    if t.lexer.level == 0:
        start = t.lexer.code_start
        end = t.lexer.lexpos - 1
        t.value = t.lexer.lexdata[start:end]
        t.type = 'RAW'
        t.lexer.lineno += t.value.count('\n')
        t.lexer.pop_state()
        return t

def t_raw_nonspace(t):
    r'[^\s\{\}]+'

def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

def t_raw_error(t):
    t.lexer.skip(1)

def t_error(t):
    print('Illegal character: \'%s\'' % (t.value[0]))
    t.lexer.skip(1)

def lexer(**kwargs):
    return lex.lex(**kwargs)
