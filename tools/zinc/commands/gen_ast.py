import os
from commands.base import BaseCommand
from core.ast import AST

class NodeGenerator(object):
    def __init__(self, ast, node):
        self.ast = ast
        self.node = node

    def generate(self):
        s = ''

        return s

class GenASTCommand(BaseCommand):
    name = 'gen_ast'

    def configure(self, parser):
        parser.add_argument('-n', '--namespace')
        parser.add_argument('dest')

    def run(self, args):
        ast = AST(args.namespace, args.ast)

        self.gen_tree(args.dest, ast)
        self.gen_ast(args.dest, ast)

    def gen_tree(self, dest, ast, tree = None):
        if tree is None:
            tree = ast.tree

        if not os.path.exists(dest):
            os.makedirs(dest)

        for (name, node) in tree.items():
            if isinstance(node, (dict)):
                path = os.path.join(dest, name)
                self.gen_tree(path, ast, node)
            else:
                path = os.path.join(dest, node.header_filename)
                self.gen_node(path, ast, node)

    def gen_node(self, path, ast, node):
        gen = NodeGenerator(ast, node)

        with open(path, 'w+') as f:
            f.write(gen.generate())

    def gen_ast(self, dest, ast):
        pass
