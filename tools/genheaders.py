#!/usr/bin/env python2
import ast, os, types
from jinja2 import Template

tpl = Template("""

{% macro classinit(name) -%}
inline {{ name }}({{ classattrs(classattr) }}): {{ classattrs(classattrinit, final = ' ') }}{}
{%- endmacro %}

{% macro ns(namespaces) %}
{%- if namespaces[1] -%}
namespace {{ namespaces[0] }}
{
    {{ ns(namespaces[1:]) | indent(4) | trim }}
}
{%- else -%}
class {{ namespaces[0] }}: public ast::{% if attrs.type == 'expr' %}Expression{% else %}Statement{% endif %}
{
public:
    {{ classinit(namespaces[0]) }}
{% if attrs.values is defined %}
    {{ classattrs(classattrgetter, '\n') | indent(4) }}
{%- endif %}

    void accept(ast::tools::Visitor &visitor)
    {
        visitor.visit(*this);
    }
{%- if attrs.values is defined %}

private:
    {{ classattrs(classattrdef, '\n') | indent(4) }}
{%- endif %}
};
{%- endif -%}
{% endmacro %}

#ifndef {{ classname.replace('::', '_').upper() }}_H_
#define {{ classname.replace('::', '_').upper() }}_H_

{% if attrs.headers is defined -%}
{% for header in attrs.headers -%}
#include {{ header }}
{% endfor -%}
{% endif -%}
#include "ecma/ast/ast.h"

{{ ns(classname.split('::')) }}

#endif /* {{ classname.replace('::', '_').upper() }}_H_ */
""")

simple_getter_tpl = Template("""
inline const {{ type }} {{ name }}(void) const
{
    return m_{{ name }};
}
inline {{ classname }} &{{ name }}({{ type }} {{ name }})
{
    m_{{ name }} = {{ name }};
    return *this;
}
""")

pointer_getter_tpl = Template("""
inline {{ type }}{{ name }}(void) const
{
    return m_{{ name }}.get();
}
inline {{ classname }} &{{ name }}({{ type }} {{ name }})
{
    m_{{ name }}.reset({{ name }});
    return *this;
}
inline {{ type }}take{{ name | capitalize }}(void)
{
    return m_{{ name }}.release();
}
""")

def classattr(value):
    if '*' in value['type']:
        s = '%s%s' % (value['type'], value['name'])
    else:
        s = '%s %s' % (value['type'], value['name'])

    if 'default' in value.keys():
        s += ' = %s' % (value['default'])
    return s

def classattrdef(value):
    ty = value['type']
    if '*' in ty:
        ty = 'std::unique_ptr<%s>' % (ty[:ty.rindex('*')].strip())

    s = '%s m_%s;' % (ty, value['name'])

    return s

def classattrinit(value):
    initializer = '%s' % (value['name'])

    if 'initializer' in value:
        initializer = value['initializer'].format(**value)

    return 'm_%s(%s)' % (value['name'], initializer)

def classattrgetter(value):
    if '*' in value['type']:
        tpl = pointer_getter_tpl
    else:
        tpl = simple_getter_tpl

    keys = locals()
    keys['type'] = value['type']
    keys['name'] = value['name']
    keys['classname'] = classname

    return tpl.render(keys)

def classattrs(fmt, sep = ', ', final = ''):
    ll = []

    if 'values' in attrs.keys():
        for value in attrs['values']:
            if isinstance(fmt, (types.FunctionType)):
                ll.append(fmt(value))
            else:
                ll.append(fmt.format(**value))

    s = sep.join(ll).strip()
    if len(ll) > 0:
        s += final

    return s

if __name__ == '__main__':
    for (classname, attrs) in ast.classes_attr:
        if attrs:
            if attrs['gen']:
                keys = {
                    'ast': ast,
                    'classname': classname,
                    'attrs': attrs,
                    'classattr': classattr,
                    'classattrdef': classattrdef,
                    'classattrinit': classattrinit,
                    'classattrgetter': classattrgetter,
                    'classattrs': classattrs
                }

                header = tpl.render(keys).strip()
                lines = header.splitlines()
                header = ''
                for line in lines:
                    header += '%s\n' % (line.rstrip())

                outfilename = os.path.join(os.path.dirname(__file__), '..', 'include', '%s.h' % (classname.replace('::', '/').lower()))
                outfilename = os.path.relpath(outfilename)

                print 'Generating : %s' % (classname)
                outfile = open(outfilename, 'w+')
                outfile.write(header)
                outfile.close()
