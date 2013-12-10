import os
import textwrap
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

class WBuffer(object):
    def __init__(self):
        self.content = ''

        self.indent = 0
        self.indent_char = ' '

    def write_raw(self, data = ''):
        self.content += str(data)

    def write(self, data = ''):
        self.write_raw(textwrap.indent(str(data), self.indent * self.indent_char))

    def writeln(self, data = ''):
        self.write(data)
        self.write('\n')
    line = writeln

    def __add__(self, other):
        self.writeln(other)
        return self

    def sub(self):
        return SubWBuffer(self)

    def flush(self):
        content = self.content
        self.content = ''
        return content

    def __str__(self):
        return self.content

class SubWBuffer(WBuffer):
    def __init__(self, writer):
        super().__init__()
        self.writer = writer

    def __enter__(self):
        return self

    def __exit__(self, *args):
        self.writer.write(self.flush())

class Writer(WBuffer):
    def __init__(self, stream):
        super().__init__()
        self.stream = stream

    def flush(self):
        self.stream.write(super().flush())

class Writeable(object):
    def write(self, w):
        pass

    def __str__(self):
        w = WBuffer()
        self.write(w)
        return w.flush()

    def __repr__(self):
        return str(self)
