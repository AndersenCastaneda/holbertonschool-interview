#!/usr/bin/python3
"""Rotate Matrix to the right"""


def rotate_2d_matrix(matrix):

    lenght = len(matrix)
    matrix_copy = [row[:] for row in matrix]

    for i in range(lenght):
        for j in range(lenght):
            matrix[j][(lenght - 1) - i] = matrix_copy[i][j]
