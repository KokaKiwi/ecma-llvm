from collections import OrderedDict
from .lexer import Lexer
from ast.ast import *

class Mapping(object):
    def __init__(self, value, mapping):
        self.value = value
        self.mapping = mapping

        self.prepare()

    def prepare(self):
        self.maps = OrderedDict()

        self.prepare_value()

    def prepare_value(self):
        self.letter = ord('A')

        def check_key(index):
            key = '${:d}'.format(index)

            if key in self.mapping:
                idx = int(key[1:])
                self.maps[idx] = chr(self.letter)
                self.mapping = self.mapping.replace(key, chr(self.letter))

                self.letter += 1

        if self.mapping is not None:
            for i in range(1 + len(self.value.items)):
                check_key(i)

    def get(self, index):
        if index in self.maps.keys():
            return self.maps[index]

        return None

    def format(self):
        lines = self.mapping.splitlines()

        if len(lines) > 1:
            last = lines[-1]
            size = len(last)

            nlines = []
            for line in lines:
                nline = line[size:]
                nlines.append(nline)

            lines = nlines
        else:
            line = lines[0]
            line = ' '*4 + line.strip()

            lines = [
                '',
                line,
                '',
            ]

        return '\n'.join(lines)

    def __str__(self):
        s = ''

        if self.mapping is not None:
            s += self.format()

        return s

class Item(object):
    def __init__(self, value, idx, item):
        self.value = value
        self.index = idx
        self.item = item

    def __str__(self):
        s = '{:s}'.format(self.item)

        m = self.value.mapping.get(self.index + 1)
        if m is not None:
            s += '({:s})'.format(m)

        return s

class Parser(object):
    def __init__(self, ast):
        self.ast = ast
        self.lexer = Lexer(ast)

        self.prepare()

    def prepare(self):
        for d in self.ast.defs:
            rule = d.rule
            for value in rule.values:
                items = []
                for (i, item) in enumerate(value.items):
                    if not isinstance(item, (Ident)):
                        item = Ident(self.lexer.name(item))
                    items.append(Item(value, i, item))

                value.items = items
                value.mapping = Mapping(value, value.mapping)
