from core import utils
from core.lexer import Lexer
from commands.base import BaseCommand
from ast.ast import *

class GenLexerCommand(BaseCommand):
    name = 'gen_lexer'

    def configure(self, parser):
        parser.add_argument('source')
        parser.add_argument('dest')

    def run(self, args):
        lexer = Lexer(args.ast)

        content = self.gen_lexer(lexer)
        utils.gen_from_template(args.source, args.dest, lexer = content)

    def gen_lexer(self, lexer):
        s = ''

        for (g_name, g_tokens) in lexer.tokens.items():
            s += '# {:s}\n'.format(g_name)
            for (name, token) in g_tokens.items():
                def output_token(token):
                    if isinstance(token, (Regex)):
                        fmt = '{}'
                        token = token[:]
                    else:
                        fmt = '"{}"'
                    return fmt.format(token)

                s += '{token:23s} =>  {{ type = ECMA_TOKEN({name:s}); fbreak; }};\n'.format(name = name, token = output_token(token))
            s += '\n'

        return s
