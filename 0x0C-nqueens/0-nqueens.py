#!/usr/bin/python3
"""N Queens"""
import sys


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    size = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)

if size < 4:
    print("N must be at least 4")
    exit(1)

k = 1


def print_board(board):
    """Prints solution"""
    arr = []
    global k
    k += 1
    for i in range(size):
        for j in range(size):
            if board[i][j] == 1:
                arr.append([i, j])
    print(arr)


def check_safe(board, row, col):
    """Checks if a queen can be placed on board[i][j]"""
    for i in range(col):
        if board[row][i]:
            return False

    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j]:
            return False
        i -= 1
        j -= 1

    i = row
    j = col
    while j >= 0 and i < size:
        if board[i][j]:
            return False
        i += 1
        j -= 1
    return True


def recursion(board, col):
    """Recursion call to solve NQueen problem"""
    if col == size:
        print_board(board)
        return True

    res = False
    for i in range(size):
        if check_safe(board, i, col):
            board[i][col] = 1
            res = recursion(board, col + 1) or res
            board[i][col] = 0
    return res


def backtracking():
    """Backtracking"""
    board = [[0 for j in range(size)] for i in range(size)]
    if recursion(board, 0) is False:
        return
    return

backtracking()
