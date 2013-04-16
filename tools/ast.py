import yaml, os
from collections import OrderedDict

ast_file = open(os.path.join(os.path.dirname(__file__), 'ast.yml'))
ast_data = ast_file.read()
ast_file.close()

def omap_constructor(loader, node):
    return OrderedDict(loader.construct_pairs(node))
yaml.add_constructor(u'!omap', omap_constructor)

data = yaml.load(ast_data)

ast = data['ast']

classes = []
classes_attr = []

def create_classes(namespace, tree):
    for (key, value) in tree.items():
        if isinstance(value, (OrderedDict)):
            create_classes('%s::%s' % (namespace, key), value)
        else:
            classes.append('%s::%s' % (namespace, key))
            classes_attr.append(('%s::%s' % (namespace, key), value))

create_classes('ecma::ast', ast)
