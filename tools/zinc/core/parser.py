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

    def clone(self):
        return Item(self.value, self.index, self.item)

    def __getattr__(self, name):
        return self.item.__getattr__(name)

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
        self.filter_unused()
        self.resolve_variants()

    def prepare(self):
        for d in self.ast.defs:
            rule = d.rule
            for value in rule.values:
                items = []
                for (i, item) in enumerate(value.items):
                    if not isinstance(item.value, (Ident)):
                        item.value = Ident(self.lexer.name(item.value))
                    items.append(Item(value, i, item))

                value.items = items
                value.mapping = Mapping(value, value.mapping)

    def filter_unused(self):
        defs = []

        for d in self.ast.defs:
            if not d.unused:
                defs.append(d)

        self.ast.defs = defs

    def resolve_variants(self):
        defs = []

        for d in self.ast.defs:
            defs.append(d)

            variants = []
            variants += self.variants(d)

            defs += variants

        self.ast.defs = defs

    def variants(self, d):
        class Variant(object):
            def __init__(self, name):
                self.name = name
                self.values = []
                self.items = OrderedDict()

            def put_item(self, i, j, pattern):
                if i not in self.items.keys():
                    self.items[i] = OrderedDict()

                self.items[i][j] = pattern

        changes = OrderedDict()

        def get_variant(name):
            if name not in changes.keys():
                changes[name] = Variant(name)

            return changes[name]

        rule = d.rule
        for (i, value) in enumerate(rule.values):
            # Check value
            if value.variant:
                variant_name = value.variant.format(rule.name)
                variant = get_variant(variant_name)

                variant.values.append(i)

            # Check items
            for (j, item) in enumerate(value.items):
                if item.variants:
                    for v in item.variants:
                        variant_name = v.format(rule.name)
                        variant = get_variant(variant_name)

                        variant.put_item(i, j, v)

        variants = []

        for (name, variant) in changes.items():
            values = []
            for (i, value) in enumerate(rule.values):
                if i not in variant.values:
                    if i in variant.items.keys():
                        idx = variant.items[i]
                        items = []
                        for (j, item) in enumerate(value.items):
                            if j in idx.keys():
                                variant_name = idx[j].format(item.item.value)

                                new_item = item.clone()
                                new_item.item = ASTItem(Ident(variant_name), item.item.attrs)
                                items.append(new_item)
                            else:
                                items.append(item)
                        new_value = RuleValue(items = items, attrs = value.attrs, mapping = value.mapping)
                        values.append(new_value)
                    else:
                        values.append(value)

            new_rule = Rule(name, values)
            new_def = Definition(d.attrs, rule = new_rule)
            variants.append(new_def)

        return variants
