#!/usr/bin/python3
"""minOperations Module"""


def minOperations(n):
    """Calculates the fewest number of operations needed
    to result in exactly n H characters in the file"""
    letters = 1
    oprt = 0
    copy = 0

    while letters < n:
        if n % letters == 0:
            copy = letters
            oprt += 1

        letters += copy
        oprt += 1

    return oprt


if __name__ == "__main__":
    pass
