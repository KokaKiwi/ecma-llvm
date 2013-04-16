#!/usr/bin/env python2
import ast, os
from jinja2 import Template

tpl = Template("""
#ifndef ECMA_AST_AST_H_
#define ECMA_AST_AST_H_

{{ genast(ast.classes) }}

#endif /* ECMA_AST_AST_H_ */
""")

def genast(classes):
    s = ''

    for classname in classes:
        filename = classname.replace('::', '/').lower()
        s += '#include "%s.h"' % (filename)
        if classname != classes[-1]:
            s += '\n'

    return s

if __name__ == '__main__':
    keys = {
        'ast': ast,
        'genast': genast
    }

    header = tpl.render(keys).strip()

    outfilename = os.path.join(os.path.dirname(__file__), '..', 'include/ecma/ast/ast.h')
    outfilename = os.path.relpath(outfilename)

    outfile = open(outfilename, 'w+')
    outfile.write(header + '\n')
    outfile.close()
