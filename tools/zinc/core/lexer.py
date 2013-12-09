from collections import OrderedDict
from ast.ast import *

class Lexer(object):
    def __init__(self, ast):
        self.ast = ast

        self.prepare()

    def prepare(self):
        self.tokens = OrderedDict()

        self.prepare_ast()

        self.sort_tokens()

    def prepare_ast(self):
        tokens = self.ast.attr('tokens', raw = True)
        for token in tokens:
            name = None
            params = token.params
            if len(params) > 0 and isinstance(params[0], (str)):
                name = token.params[0]
                params = params[1:]

            tokens = OrderedDict()
            for param in params:
                if isinstance(param, (Named)):
                    tokens[param.name] = param.value

            if name not in self.tokens.keys():
                self.tokens[name] = OrderedDict()

            self.tokens[name].update(tokens)

    def sort_tokens(self):
        sorted_tokens = OrderedDict()
        for (g_name, g_tokens) in self.tokens.items():
            tokens = list(g_tokens.items())

            def token_cmp(tok):
                (name, token) = tok
                return len(token)

            tokens = sorted(tokens, key = token_cmp, reverse = True)

            sorted_tokens[g_name] = OrderedDict(tokens)
        self.tokens = sorted_tokens

    def token(self, name, group = None):
        tokens = OrderedDict()

        if group is None:
            for t in self.tokens.values():
                tokens.update(t)
        else:
            tokens.update(self.tokens[group])

        return tokens[name]

    def name(self, token, group = None):
        tokens = OrderedDict()

        if group is None:
            for t in self.tokens.values():
                tokens.update(t)
        else:
            tokens.update(self.tokens[group])

        tokens = OrderedDict([(val, key) for (key, val) in tokens.items()])
        return tokens[token]
