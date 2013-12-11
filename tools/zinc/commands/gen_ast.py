import os
from commands.base import BaseCommand
from core.ast import AST
from core.utils import *

HEADER_CONSTANT = '{name:s}_H_'

class NodeGenerator(Writeable):
    def __init__(self, ast, node):
        self.ast = ast
        self.node = node

    def write(self, w):
        header_constant = self.node.namespace + [self.node.name]
        header_constant = '_'.join(header_constant)
        header_constant = HEADER_CONSTANT.format(name = header_constant.upper())
        w += '#ifndef {:s}'.format(header_constant)
        w += '#define {:s}'.format(header_constant)
        w.writeln()

        self.write_body(w)

        w.writeln()
        w += '#endif /* {:s} */'.format(header_constant)

    def write_body(self, w):
        self.write_includes(w)

        with self.write_namespace(self.node.namespace, w) as ww:
            self.write_class(ww)

    def write_includes(self, w):
        includes = set([
        ])
        includes |= self.node.includes

        for inc in includes:
            w += '#include {:s}'.format(inc)

        if len(includes) > 0:
            w.writeln()

    def write_class(self, w):
        s = 'class {:s}'.format(self.node.name)
        if len(self.node.parents) > 0:
            parents = map(lambda s: 'public {:s}'.format(s), self.node.parents)
            s += ': {:s}'.format(', '.join(parents))
        w += s
        w += '{'

        with w.sub_indent() as ww:
            self.write_class_body(ww)

        w += '};'

    def write_class_body(self, w):
        w += 'public:'
        with w.sub_indent() as ww:
            self.write_class_public(ww)

        w.writeln()
        w += 'private:'
        with w.sub_indent() as ww:
            self.write_class_members(ww)

    def write_class_public(self, w):
        self.write_class_constructor(w)
        self.write_class_methods(w)

    def write_class_constructor(self, w):
        s = 'inline {:s}()'.format(self.node.name)

        w += s
        w += '{}'

    def write_class_methods(self, w):
        for item in self.node.items.values():
            w.writeln()
            self.write_class_method(w, item)

    def write_class_method(self, w, item):
        if item.pointer:
            self.write_class_method_pointer(w, item)
        elif item.list:
            self.write_class_method_list(w, item)
        else:
            self.write_class_method_base(w, item)

    def write_class_method_pointer(self, w, item):
        itype = item.rawtype.params[0]
        if not isinstance(itype, (str)):
            itype = item.resolve_type(itype)

        # Getter
        w += 'inline const {type:s} *{name:s}() const'.format(type = itype, name = item.name)
        w += '{'

        with w.sub_indent() as ww:
            ww += 'return {name:s}.get();'.format(name = item.varname)

        w += '}'

        # Setter
        w += 'inline {ntype:s} &{name:s}({type:s} *{name:s})'.format(type = itype, name = item.name, ntype = self.node.name)
        w += '{'

        with w.sub_indent() as ww:
            ww += '{varname:s}.reset({name:s});'.format(varname = item.varname, name = item.name)
            ww += 'return *this;'

        w += '}'

        # Taker
        w += 'inline {type:s} *{name:s}()'.format(type = itype, name = item.name)
        w += '{'

        with w.sub_indent() as ww:
            ww += 'return {name:s}.release();'.format(name = item.varname)

        w += '}'

    def write_class_method_list(self, w, item):
        itype = item.resolve_type(item.rawtype, nowrap = True)

        # Getter
        w += 'inline const {type:s} *{name:s}() const'.format(type = itype, name = item.name)
        w += '{'

        with w.sub_indent() as ww:
            ww += 'return {name:s}.get();'.format(name = item.varname)

        w += '}'

        # Setter
        w += 'inline {ntype:s} &{name:s}({type:s} *{name:s})'.format(type = itype, name = item.name, ntype = self.node.name)
        w += '{'

        with w.sub_indent() as ww:
            ww += '{varname:s}.reset({name:s});'.format(varname = item.varname, name = item.name)
            ww += 'return *this;'

        w += '}'

        # Taker
        w += 'inline {type:s} *{name:s}()'.format(type = itype, name = item.name)
        w += '{'

        with w.sub_indent() as ww:
            ww += 'return {name:s}.release();'.format(name = item.varname)

        w += '}'

    def write_class_method_base(self, w, item):
        # Getter
        w += 'inline const {type:s} {name:s}() const'.format(type = item.type, name = item.name)
        w += '{'

        with w.sub_indent() as ww:
            ww += 'return {varname:s};'.format(varname = item.varname)

        w += '}'

        # Setter
        w += 'inline {ntype:s} &{name:s}({type:s} {name:s})'.format(type = item.type, name = item.name, ntype = self.node.name)
        w += '{'

        with w.sub_indent() as ww:
            ww += '{varname:s} = {name:s};'.format(varname = item.varname, name = item.name)
            ww += 'return *this;'

        w += '}'

    def write_class_members(self, w):
        for item in self.node.items.values():
            self.write_class_member(w, item)

    def write_class_member(self, w, item):
        w += '{:s} {:s};'.format(item.type, item.varname)

    def write_namespace(self, namespace, w):
        class NamespaceWriter(SubWBuffer):
            def __init__(self, namespace, w):
                super().__init__(w)
                self.namespace = namespace

            def __enter__(self):
                for name in self.namespace:
                    self += 'namespace {:s}'.format(name)
                    self += '{'
                    self.indent += 4
                return super().__enter__()

            def __exit__(self, *args):
                for name in self.namespace:
                    self.indent -= 4
                    self += '}'
                super().__exit__(*args)

        return NamespaceWriter(namespace, w)

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
            w = Writer(f)
            gen.write(w)
            w.flush()

    def gen_ast(self, dest, ast):
        path = os.path.join(dest, 'ast.h')

        with open(path, 'w+') as f:
            w = Writer(f)
            self.write_ast(w, ast)
            w.flush()

    def write_ast(self, w, ast):
        header_constant = ast.namespace.split('::') + ['ast']
        header_constant = '_'.join(header_constant)
        header_constant = HEADER_CONSTANT.format(name = header_constant.upper())

        incdir = ast.namespace.replace('::', '/')

        w += '#ifndef {:s}'.format(header_constant)
        w += '#define {:s}'.format(header_constant)
        w.writeln()

        def write_tree(w, dest, tree):
            for (name, node) in tree.items():
                if isinstance(node, (dict)):
                    path = os.path.join(dest, name)
                    write_tree(w, path, node)
                else:
                    path = os.path.join(dest, node.header_filename)
                    w += '#include "{path:s}"'.format(path = path)
        write_tree(w, incdir, ast.tree)

        w.writeln()
        w += '#endif /* {:s} */'.format(header_constant)
