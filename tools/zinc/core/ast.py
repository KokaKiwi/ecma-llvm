import os
from collections import OrderedDict
from ast import ast as ast_ast

class Item(object):
    VARNAME     = 'm_{name:s}'

    def __init__(self, node, name, attrs):
        self.node = node
        self.name = name
        self.attrs = attrs

        self.prepare()

    def prepare(self):
        self.prepare_type()

    def prepare_type(self):
        ty = self.type
        self.rawtype = ty
        if isinstance(ty, (str)):
            self.pointer = self.list = False
        elif isinstance(ty, (ast_ast.Func)):
            self.pointer = ty.param('pointer', False)
            self.list = ty.param('list', False)
            self.type = self.resolve_type(ty)

    def resolve_type(self, ty, nowrap = False):
        name = ty.params[0]
        if isinstance(name, (ast_ast.Func)):
            name = self.resolve_type(name)

        force_pointer = False
        if ty.list:
            self.node.add_include('<vector>')
            name = 'std::vector<{:s}>'.format(name)
            # force_pointer = True

        if ty.pointer or (force_pointer and not nowrap):
            self.node.add_include('<memory>')
            name = 'std::unique_ptr<{:s}>'.format(name)

        if ty.name == 'enum':
            self.node.enums[name] = ty.params[1]

        return name

    @property
    def itype(self):
        itype = self.rawtype
        if not isinstance(self.rawtype, (str)):
            itype = self.rawtype.params[0]
            if not isinstance(itype, (str)):
                itype = self.resolve_type(itype)

        return itype

    @property
    def varname(self):
        name = self.VARNAME.format(name = self.name)

        return name

    def __getattr__(self, name):
        return self.attrs.__getattr__(name)

class Node(object):
    def __init__(self, ast, namespace, attrs):
        self.ast = ast
        self.namespace = namespace
        self.attrs = attrs
        self.includes = []
        self.enums = OrderedDict()

        self.type = '::'.join(namespace + [self.name])

        self.prepare()

    def add_include(self, inc):
        if isinstance(inc, (list)):
            for i in inc:
                self.add_include(i)
        elif inc is not None:
            if inc not in self.includes:
                if inc[0] == '<':
                    self.includes.insert(0, inc)
                else:
                    self.includes.append(inc)

    def prepare(self):
        self.prepare_includes()
        self.prepare_items()

    def prepare_includes(self):
        self.add_include(self.attrs.includes)

        def find_node(tree, path):
            if len(path) == 0:
                return None
            name = path[0]
            if name not in tree.keys():
                return None
            if isinstance(tree[name], (map)):
                return find_node(tree[name], path[1:])
            else:
                return tree[name]

        for parent in self.parents:
            path = parent.split('::')
            node = find_node(self.ast.tree, path)
            if node:
                header_dirname = '/'.join(path[:-1])
                header = os.path.join(self.ast.path, header_dirname, node.header_filename)
                self.add_include('"{:s}"'.format(header))

    def prepare_items(self):
        self.items = OrderedDict()

        for item in self.attrs.attr('items', []):
            name = item.params[0]
            attrs = ast_ast.Node(item.params[1:])

            self.items[name] = Item(self, name, attrs)

    @property
    def basename(self):
        basename = self.attrs.basename
        if basename:
            return basename
        return self.name.lower()

    @property
    def source_filename(self):
        return '{:s}.cpp'.format(self.basename)

    @property
    def header_filename(self):
        return '{:s}.h'.format(self.basename)

    @property
    def parents(self):
        parents = self.attrs.parents
        if parents:
            return parents

        parent = self.attrs.parent
        if parent:
            return [parent]

        return []

    def __getattr__(self, name):
        return self.attrs.__getattr__(name)

class AST(object):
    def __init__(self, namespace, ast):
        self.namespace = namespace
        self.ast = ast

        self.prepare()

    def prepare(self):
        self.tree = OrderedDict()

        self.prepare_ast()

    def prepare_ast(self):
        def place_node(tree, namespace, node):
            if len(namespace) > 0:
                name = namespace[0]
                if name not in tree.keys():
                    tree[name] = OrderedDict()
                place_node(tree[name], namespace[1:], node)
            else:
                name = node.name
                tree[name] = node


        ast = self.ast.attr('ast', raw = True)
        for node in ast:
            node = ast_ast.Node(node.params)

            namespace = self.namespace.split('::')
            node_namespace = []
            if node.namespace:
                node_namespace = node.namespace.split('::')
            namespace += node_namespace

            place_node(self.tree, node_namespace, Node(self, namespace, node))

    @property
    def path(self):
        return self.namespace.replace('::', '/')
