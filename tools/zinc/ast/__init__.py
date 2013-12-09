from . import parser

def parse(filename, **kwargs):
    with open(filename, 'r') as f:
        content = f.read()

    return parser.parse(content, **kwargs)
