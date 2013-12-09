from core import utils
from core.lexer import Lexer
from commands.base import BaseCommand

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

        for (g_name, g_tokens) in lexer.tokens.items():
            s += '// {:s}\n'.format(g_name)
            for name in g_tokens.keys():
                s += 'ECMA_TOKEN({name:s})\n'.format(name = name)
            s += '\n'

        return s
