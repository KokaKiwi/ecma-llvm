import os
import subprocess
from glob import glob

def run_parser(*args):
    return subprocess.call(args)

def test_success(ecmac, path):
    args = [ecmac, '-P', path]
    ret = True if run_parser(*args) == 0 else False

    ret_text = "success" if ret else "fail"
    basename = os.path.basename(path)

    print('{name:s}...{text:s}'.format(name = basename, text = ret_text))

    return ret

def test_fail(ecmac, path):
    args = [ecmac, '-P', path]
    ret = True if run_parser(*args) == 1 else False

    ret_text = "success" if ret else "fail"
    basename = os.path.basename(path)

    print('{name:s}...{text:s}'.format(name = basename, text = ret_text))

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
