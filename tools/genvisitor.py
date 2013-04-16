#!/usr/bin/env python2
import ast, os
from jinja2 import Template
from collections import OrderedDict

tpl = Template("""
#ifndef ECMA_AST_TOOLS_VISITOR_H_
#define ECMA_AST_TOOLS_VISITOR_H_

#include <stdexcept>

namespace ecma
{
    namespace ast
    {
{{ gentree(2, ast.ast) }}
        namespace tools
        {
            class Visitor
            {
            public:
                inline ~Visitor() {}
{{ genvisit(4, ast.classes) }}
            };
        }
    }
}

#endif /* ECMA_AST_TOOLS_VISITOR_H_ */
""")

def indent(depth):
    return '    ' * depth

def gentree(depth, tree):
    s = ''
    for (key, value) in tree.items():
        if isinstance(value, (OrderedDict)):
            s += '\n%snamespace %s\n' % (indent(depth), key)
            s += '%s{\n' % (indent(depth))
            s += '%s' % (gentree(depth + 1, value))
            s += '%s}\n' % (indent(depth))
        else:
            s += '%sclass %s;\n' % (indent(depth), key)
    return s

def genvisit(depth, classes):
    s = ''
    for classname in classes:
        classname = '::'.join(classname.split('::')[1:])
        s += '\n%svirtual inline void visit(%s &node)\n' % (indent(depth), classname)
        s += '%s{\n' % (indent(depth))
        s += '%s    throw std::runtime_error("Unknown AST branch (%s).");\n' % (indent(depth), classname)
        s += '%s}\n' % (indent(depth))
    return s

if __name__ == '__main__':
    keys = {
        'ast': ast,
        'gentree': gentree,
        'genvisit': genvisit
    }
    header = tpl.render(keys).strip()

    outfilename = os.path.join(os.path.dirname(__file__), '..', 'include/ecma/ast/tools/visitor.h')
    outfilename = os.path.relpath(outfilename)

    outfile = open(outfilename, 'w+')
    outfile.write(header + '\n')
    outfile.close()
