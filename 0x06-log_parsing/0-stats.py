#!/usr/bin/python3
""" Log Parsing """

import sys

counts = {
    'lines': 1,
    'size': 0
}

status_codes = {
    '200': 0, '301': 0, '400': 0, '401': 0,
    '403': 0, '404': 0, '405': 0, '500': 0
}


def print_values():
    """Prints Total size and status codes"""
    print('File size: {}'.format(counts['size']))
    for key in sorted(status_codes.keys()):
        if status_codes[key] > 0:
            print('{}: {}'.format(key, status_codes[key]))


def read_values(line):
    """Keep total size count and status codes"""
    counts['size'] += int(line[-1])
    if line[-2] in status_codes:
        status_codes[line[-2]] += 1


if __name__ == '__main__':
    try:
        for line in sys.stdin:
            try:
                read_values(line.split(' '))
            except:
                pass
            if counts['lines'] % 10 == 0:
                print_values()
            counts['lines'] += 1
    except KeyboardInterrupt:
        print_values()
        raise
    print_values()
