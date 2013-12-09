import os
from jinja2 import Template

def smart_indent(text, indent = 4, first = False):
    lines = text.splitlines()
    ret = []

    for (i, line) in enumerate(lines):
        s = ''

        if i > 0 or first:
            s += ' ' * indent

        s += line

        s = s.rstrip(' ')
        ret.append(s)

    return '\n'.join(ret)

def gen_from_template(src, dst, **kwargs):
    with open(src, 'r') as f:
        tpl = Template(f.read())

    dst_dir = os.path.dirname(dst)
    if not os.path.exists(dst_dir):
        os.makedirs(dst_dir)

    kwargs['smart_indent'] = smart_indent

    with open(dst, 'w+') as f:
        f.write(tpl.render(**kwargs))
