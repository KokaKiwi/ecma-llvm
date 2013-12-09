#!/usr/bin/env python3
import sys
import commands
import ast
from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument('--ast', metavar = 'FILE', help = 'AST definition file.')
parser.add_argument('-d', '--debug', action = 'store_true', help = 'Enable debug output.')

subparsers = parser.add_subparsers(dest = 'command', help = 'Sub-commands')
commands.configure(subparsers)

def main(argv = sys.argv[1:]):
    args = parser.parse_args(argv)
    args.ast = ast.parse(args.ast, debug = args.debug)

    command = args.command
    commands.run(command, args)

if __name__ == '__main__':
    main()
