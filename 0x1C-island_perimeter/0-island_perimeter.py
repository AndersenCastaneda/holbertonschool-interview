#!/usr/bin/python3
"""IslandPerimeter Module"""


def island_perimeter(grid):
    """calculate the perimeter of an island
    Args:
        grid ([type]): List of list of integers
    Returns:
        perimeter of the island inside the grid
    """

    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] != 0:
                if i - 1 < 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                if i + 1 >= len(grid) or grid[i + 1][j] == 0:
                    perimeter += 1
                if j - 1 < 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                if j + 1 >= len(grid[i]) or grid[i][j + 1] == 0:
                    perimeter += 1
    return perimeter
