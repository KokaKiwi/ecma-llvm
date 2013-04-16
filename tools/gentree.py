#!/usr/bin/env python2
import ast

def indent(depth):
    return '    ' * depth

def print_tree(depth, tree):
    for (key, value) in tree.items():
        if isinstance(value, (dict)):
            print '\n%snamespace %s' % (indent(depth), key)
            print '%s{' % (indent(depth))
            print_tree(depth + 1, value)
            print '%s}' % (indent(depth))
        else:
            print '%sclass %s;' % (indent(depth), key)

print_tree(0, ast.ast)
