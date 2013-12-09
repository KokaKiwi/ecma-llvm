import os
import importlib
from .base import BaseCommand

excludes = [
    '__init__.py',
    '__pycache__',
    'base.py',
]


for entry in os.listdir(os.path.dirname(__file__)):
    if entry not in excludes:
        if entry.endswith('.py'):
            entry = entry[:-3]
        importlib.import_module('.' + entry, package = __package__)

COMMANDS = BaseCommand.__subclasses__()
COMMANDS = [Command() for Command in COMMANDS]
COMMANDS = dict([(command.name, command) for command in COMMANDS])

def configure(subparsers):
    for command in COMMANDS.values():
        if command.name is not None:
            subparser = subparsers.add_parser(command.name, help = command.help)
            command.configure(subparser)

def run(name, args):
    command = COMMANDS[name]
    command.run(args)
