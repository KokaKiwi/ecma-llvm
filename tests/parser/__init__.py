import os
import subprocess
from glob import glob

def run_parser(*args):
    return subprocess.call(args)

def test_success(ecmap, path):
    args = [ecmap, path]
    ret = True if run_parser(*args) == 0 else False

    ret_text = "success" if ret else "fail"
    basename = os.path.basename(path)

    print('{name:s}...{text:s}'.format(name = basename, text = ret_text))

    return ret

def test_fail(ecmap, path):
    args = [ecmap, path]
    ret = True if run_parser(*args) == 1 else False

    ret_text = "success" if ret else "fail"
    basename = os.path.basename(path)

    print('{name:s}...{text:s}'.format(name = basename, text = ret_text))

    return ret

def run_tests(t):
    ecmap = os.path.join(t.bin_dir, 'ecmap')
    tests_dir = os.path.join(t.tests_dir, 'parser')

    tests_success = glob(os.path.join(tests_dir, 'success', '*.js'))
    tests_fail = glob(os.path.join(tests_dir, 'fail', '*.js'))

    success = True

    for path in tests_success:
        if not test_success(ecmap, path):
            success = False

    for path in tests_fail:
        if not test_fail(ecmap, path):
            success = False

    return success
