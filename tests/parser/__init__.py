import os
import subprocess
import re
from glob import glob

TEST_MSG = '[{test_name:^14s}] {name:32s} ... {status:s}'

def run_parser(ecmac, *args):
    cargs = [ecmac, '-P', '--no-color'] + list(args)
    proc = subprocess.Popen(cargs, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
    proc.wait()

    return proc

def test_success(ecmac, path):
    proc = run_parser(ecmac, path)
    ret = proc.returncode == 0

    ret_text = "success" if ret else "fail"
    basename = os.path.basename(path)

    print(TEST_MSG.format(test_name = 'success-test', name = basename, status = ret_text))

    return ret

def check_error(error):
    filename = error.group('filename')
    with open(filename, 'r') as f:
        source = f.read()

    lines = source.splitlines() + ['']

    line = int(error.group('line'))
    column = int(error.group('column'))

    source_line = lines[line - 1]

    message = error.group('message')

    if '<~~' in source_line:
        source_msg = source_line.split('<~~')[-1].strip()

        if message != source_msg:
            print('FAIL: Bad error message!')
            print('  Have     : {}'.format(message))
            print('  Expected : {}'.format(source_msg))

            return False

    return True

def test_fail(ecmac, path):
    proc = run_parser(ecmac, path)
    ret = proc.returncode == 1

    ERROR_PATTERN = r'(?P<filename>/[^:]+):(?P<line>[0-9]+):(?P<column>[0-9]+): error: (?P<message>[^\\]*)'
    error_pattern = re.compile(ERROR_PATTERN)

    stderr = str(proc.stderr.read())
    errors = []

    for line in stderr.splitlines():
        error = error_pattern.search(line)
        if error:
            errors.append(error)

    for error in errors:
        if not check_error(error):
            ret = False

    ret_text = "success" if ret else "fail"
    basename = os.path.basename(path)

    print(TEST_MSG.format(test_name = 'fail-test', name = basename, status = ret_text))

    return ret

def run_tests(t):
    ecmac = os.path.join(t.bin_dir, 'ecmac')
    tests_dir = os.path.join(t.tests_dir, 'parser')

    tests_success = glob(os.path.join(tests_dir, 'success', '*.js'))
    tests_fail = glob(os.path.join(tests_dir, 'fail', '*.js'))

    success = True

    for path in tests_success:
        if not test_success(ecmac, path):
            success = False

    for path in tests_fail:
        if not test_fail(ecmac, path):
            success = False

    return success
