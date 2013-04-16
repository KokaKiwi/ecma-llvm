#!/usr/bin/env python2
import ast

tpl="""virtual inline void visit({classname} &{varname})
{{
    throw std::runtime_error("Unknown AST branch ({classname}).");
}}
"""

for classname in ast.classes:
    varname = 'node'
    classname = '::'.join(classname.split('::')[1:])
    print tpl.format(classname = classname, varname = varname)
