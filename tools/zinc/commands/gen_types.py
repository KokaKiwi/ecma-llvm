from core import utils
from core.lexer import Lexer
from commands.base import BaseCommand
from ast.ast import *

class GenTypesCommand(BaseCommand):
    name = 'gen_types'

    def configure(self, parser):
        parser.add_argument('source')
        parser.add_argument('dest')

    def run(self, args):
        lexer = Lexer(args.ast)

        content = self.gen_types(lexer)
        utils.gen_from_template(args.source, args.dest, types = content)

    def gen_types(self, lexer):
        s = ''

        def token_repr(name, tok):
            value = tok.params[0]
            tok_name = tok.param('name')

            if tok_name is not None:
                return tok_name
            else:
                return '\'{:s}\''.format(value)

        for (g_name, g_tokens) in lexer.tokens.items():
            s += '// {:s}\n'.format(g_name)
            for (name, tok) in g_tokens.items():
                s += 'ECMA_TOKEN({name:s}, "{text:s}")\n'.format(name = name, text = token_repr(name, tok))
            s += '\n'

        if len(lexer.raw) > 0:
            s += '// Raw\n'
        for (name, tok) in lexer.raw.items():
            s += 'ECMA_TOKEN({name:s}, "{text:s}")\n'.format(name = name, text = token_repr(name, tok))
        if len(lexer.raw) > 0:
            s += '\n'

        return s
