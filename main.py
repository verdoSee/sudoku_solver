import numpy as np

grid = [
    [8, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 3, 6, 0, 0, 0, 0, 0],
    [0, 7, 0, 0, 9, 0, 2, 0, 0],
    [0, 5, 0, 0, 0, 7, 0, 0, 0],
    [0, 0, 0, 0, 4, 5, 7, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 3, 0],
    [0, 0, 1, 0, 0, 0, 0, 6, 8],
    [0, 0, 8, 5, 0, 0, 0, 1, 0],
    [0, 9, 0, 0, 0, 0, 4, 0, 0],
]

count = 0


def possible(row, col, num):
    for i in grid[row]:
        if i == num:
            return False

    for i in grid:
        if i[col] == num:
            return False

    row0 = (row // 3) * 3
    col0 = (col // 3) * 3

    for i in range(3):
        for j in range(3):
            if grid[row0 + i][col0 + j] == num:
                return False

    return True


def solve():
    global count
    count += 1
    for i in range(9):
        for j in range(9):
            if grid[i][j] == 0:
                for n in range(1, 10):
                    if possible(i, j, n):
                        grid[i][j] = n
                        if solve():
                            return True
                        grid[i][j] = 0
                return False
    return True


if __name__ == "__main__":
    solve()
    print(np.array(grid))
    print()
    print(count)
