# Value
class Named(object):
    def __init__(self, name, value = None):
        self.name = name
        self.value = value

    def __str__(self):
        return '%s=%s' % (self.name, self.value)

class Func(object):
    def __init__(self, name, params = []):
        self.name = name
        self.params = params

    def param(self, index, default = None):
        if isinstance(index, (int)):
            return self.params[index] if 0 < index < len(self.params) else default
        elif isinstance(index, (str)):
            for param in self.params:
                if isinstance(param, (Named)) and param.name == index:
                    return param.value

        return default

    def __getattr__(self, name):
        return self.param(name)

    def __str__(self):
        return '%s(%s)' % (self.name, ', '.join(map(str, self.params)))

class Ident(str):
    pass

class Regex(str):
    def __str__(self):
        return 'r\'%s\'' % (super().__str__())

class Raw(str):
    def __str__(self):
        return '{%s}' % (super().__str__())

# AST
class Node(object):
    def __init__(self, attrs = []):
        self.attrs = attrs

    def attr(self, name, default = None, raw = False):
        result = []

        if isinstance(name, (str)):
            for attr in self.attrs:
                if isinstance(attr, (Named)) and attr.name == name:
                    result.append(attr.value)
                elif isinstance(attr, (Func)) and attr.name == name:
                    result.append(attr)
                elif isinstance(attr, (Ident)) and attr == name:
                    result.append(True)

        if len(result) > 1 or raw:
            return result
        elif len(result) == 1:
            return result[0]

        return default

    def __getattr__(self, name):
        return self.attr(name)

class AST(Node):
    def __init__(self, defs = []):
        self.defs = []
        attrs = []

        for d in defs:
            if d.rule is not None:
                self.defs.append(d)
            else:
                attrs += d.attrs

        super().__init__(attrs)

    def __str__(self):
        s = ''

        for attr in self.attrs:
            s += '#[%s]\n' % (attr)

        s += '\n'

        for d in self.defs:
            s += '%s\n' % (d)

        return s

class Definition(Node):
    def __init__(self, attrs = [], rule = None):
        super().__init__(attrs)
        self.rule = rule

    def __str__(self):
        s = ''

        s += '#[%s]' % (', '.join(map(str, self.attrs)))

        if self.rule is not None:
            s += '\n'
            s += '%s' % (self.rule)

        return s

class Rule(object):
    def __init__(self, name, values = []):
        self.name = name
        self.values = values

    def __str__(self):
        s = '%s ::=\n' % (self.name)

        s += '\n'.join(map(lambda value: '    %s' % (value), self.values))

        return s

class RuleValue(object):
    def __init__(self, items = [], mapping = None):
        self.items = items
        self.mapping = mapping

    def __str__(self):
        s = ''

        s += ' '.join(map(str, self.items))

        if self.mapping is not None:
            s += ' => %s' % (self.mapping)

        return s
