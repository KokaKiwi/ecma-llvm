from core import utils
from core.lexer import Lexer
from core.parser import Parser
from commands.base import BaseCommand
from ast.ast import *

class GenParserCommand(BaseCommand):
    name = 'gen_parser'

    def configure(self, parser):
        parser.add_argument('source')
        parser.add_argument('dest')

    def run(self, args):
        lexer = Lexer(args.ast)
        tokens = self.gen_tokens(lexer)

        parser = Parser(args.ast)
        rules = self.gen_rules(parser)

        utils.gen_from_template(args.source, args.dest, tokens = tokens, rules = rules)

    def gen_tokens(self, lexer):
        s = ''

        for (g_name, g_tokens) in lexer.tokens.items():
            tokens = list(g_tokens.keys())
            left = []
            right = []

            for token in tokens:
                if token in lexer.prec.keys():
                    prec = lexer.prec[token]
                    if prec == 'left':
                        left.append(token)
                    elif prec == 'right':
                        right.append(token)
                else:
                    left.append(token)

            if len(left) > 0:
                s += '%left {:s}.\n'.format(' '.join(left))

            if len(right) > 0:
                s += '%right {:s}.\n'.format(' '.join(right))


        return s

    def gen_rules(self, parser):
        s = ''

        for (i, d) in enumerate(parser.ast.defs):
            if i > 0:
                s += '\n'

            rule = d.rule
            s += '/* Rule \'{:s}\' */\n'.format(rule.name)

            if d.start:
                s += '%start_symbol {:s}\n'.format(rule.name)

            for value in rule.values:
                s += '\n'

                s += '{:s}'.format(rule.name)

                m = value.mapping.get(0)
                if m is not None:
                    s += '({:s})'.format(m)

                s += ' ::= {:s}.\n'.format(' '.join(map(lambda item: str(item.item.value), value.items)))
                s += '{{{:s}}}\n'.format(value.mapping)

        return s
