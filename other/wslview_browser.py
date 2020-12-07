#!/home/sergei/miniconda3/bin/python3

import sys
import os

target = sys.argv[1]

if target.startswith('file://'):
    target = target[len('file://'):]

    # wslview only works with relative paths
    target = os.path.relpath(target)

print("Opening", target)
os.system(f'wslview {target}')
