#!/usr/bin/env python
import os
import sys
import parser
from argparse import ArgumentParser

HERE = os.path.dirname(os.path.realpath(__file__))

argparser = ArgumentParser()
argparser.add_argument('--bin-dir', dest = 'bin_dir')

class Tester(object):
    pass

def main(args):
    t = Tester()
    t.bin_dir = args.bin_dir
    t.tests_dir = HERE

    print('=== Parser tests ===')
    parser_ret = parser.run_tests(t)

    if parser_ret:
        sys.exit(0)
    else:
        sys.exit(1)

if __name__ == '__main__':
    args = argparser.parse_args()
    main(args)
