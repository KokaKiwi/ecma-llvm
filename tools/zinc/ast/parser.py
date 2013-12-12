import ply.yacc as yacc
from .lexer import (tokens, literals, lexer)
from .ast import *

# AST
def p_ast(p):
    '''
        ast : def_list
    '''
    p[0] = AST(defs = p[1])

# Definitions
def p_def_list(p):
    '''
        def_list : def_list def
    '''
    p[0] = p[1] + [p[2]]

def p_def_list_empty(p):
    '''
        def_list :
    '''
    p[0] = []

# Definition
def p_def_attrs_def(p):
    '''
        def : attrs_list rule ';'
    '''
    p[0] = Definition(attrs = p[1], rule = p[2])

def p_def_attrs(p):
    '''
        def : attrs_list ';'
    '''
    p[0] = Definition(attrs = p[1])

def p_def_def(p):
    '''
        def : rule ';'
    '''
    p[0] = Definition(rule = p[1])

# Attributes list
def p_attrs_list(p):
    '''
        attrs_list : attrs_list attrs
    '''
    p[0] = p[1] + p[2]

def p_attrs_list_single(p):
    '''
        attrs_list : attrs
    '''
    p[0] = p[1]

# Attributes
def p_attrs(p):
    '''
        attrs : '#' '[' list_items ']'
    '''
    p[0] = p[3]

# Rule
def p_rule(p):
    '''
        rule : IDENT ASSIGN rule_values
    '''
    values = p[3]
    if len(values) == 0:
        values.append(RuleValue())
    p[0] = Rule(p[1], values)

# Rule values
def p_rule_values(p):
    '''
        rule_values : rule_values rule_value
    '''
    p[0] = p[1] + [p[2]]

def p_rule_values_empty(p):
    '''
        rule_values :
    '''
    p[0] = []

# Rule value
def p_rule_value(p):
    '''
        rule_value : rule_items FAT_ARROW rule_mapping
    '''
    p[0] = RuleValue(items = p[1], mapping = p[3])

def p_rule_value_no_mapping(p):
    '''
        rule_value : rule_items ','
    '''
    p[0] = RuleValue(items = p[1])

# Rule items
def p_rule_items(p):
    '''
        rule_items : rule_items rule_item
    '''
    p[0] = p[1] + [p[2]]

def p_rule_items_single(p):
    '''
        rule_items : rule_item
    '''
    p[0] = [p[1]]

# Rule item
def p_rule_item_ident(p):
    '''
        rule_item : IDENT
    '''
    p[0] = Ident(p[1])

def p_rule_item_string(p):
    '''
        rule_item : STRING
    '''
    p[0] = p[1]

# Rule mapping
def p_rule_mapping(p):
    '''
        rule_mapping : value
    '''
    p[0] = p[1]

# Value
def p_value_ident(p):
    '''
        value : IDENT
    '''
    p[0] = Ident(p[1])

def p_value_null(p):
    '''
        value : NONE
    '''
    p[0] = None

def p_value_number(p):
    '''
        value : NUMBER
    '''
    p[0] = p[1]

def p_value_string(p):
    '''
        value : STRING
    '''
    p[0] = p[1]

def p_value_regex(p):
    '''
        value : REGEX
    '''
    p[0] = Regex(p[1])

def p_value_boolean(p):
    '''
        value : BOOLEAN
    '''
    p[0] = p[1]

def p_value_raw(p):
    '''
        value : RAW
    '''
    p[0] = Raw(p[1])

def p_value_named(p):
    '''
        value : IDENT '=' value
    '''
    p[0] = Named(p[1], p[3])

def p_value_named_string(p):
    '''
        value : STRING '=' value
    '''
    p[0] = Named(p[1], p[3])

def p_value_func(p):
    '''
        value : func
    '''
    p[0] = p[1]

def p_value_list(p):
    '''
        value : list
    '''
    p[0] = p[1]

# Function
def p_func(p):
    '''
        func : IDENT '(' list_items ')'
    '''
    p[0] = Func(p[1], params = p[3])

# List
def p_list(p):
    '''
        list : '[' list_items ']'
    '''
    p[0] = p[2]

# List items
def p_list_items(p):
    '''
        list_items : list_items ',' list_item
    '''
    p[0] = p[1] + [p[3]]

def p_list_items_comma(p):
    '''
        list_items : list_items ','
    '''
    p[0] = p[1]

def p_list_items_single(p):
    '''
        list_items : list_item
    '''
    p[0] = [p[1]]

def p_list_items_empty(p):
    '''
        list_items :
    '''
    p[0] = []

# List item
def p_list_item(p):
    '''
        list_item : value
    '''
    p[0] = p[1]

# Errors
errors = []
def p_error(p):
    if p:
        print('Syntax error: Unexpected token %s ("%s") at line %d' % (p.type, p.value, p.lexer.lineno))
    else:
        print('Unexpected EOF.')

    errors.append(p)
    exit(1)
    yacc.restart()

# Main
def parse(source, **kwargs):
    parser = yacc.yacc()

    debug = kwargs['debug'] if 'debug' in kwargs.keys() else False

    return parser.parse(source, lexer = lexer(debug = debug), **kwargs)
