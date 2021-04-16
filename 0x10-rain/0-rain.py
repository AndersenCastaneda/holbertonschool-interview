#!/usr/bin/python3
""" Rain """


def rain(walls):
    """ Returns retained water """
    water = 0
    wallsLenght = len(walls)
    for i in range(1, wallsLenght - 1):
        left = walls[i]
        for k in range(i):
            left = max(left, walls[k])
        right = walls[i]
        for k in range(i + 1, wallsLenght):
            right = max(right, walls[k])
        water += (min(left, right) - walls[i])
    return water
