import math

def helper(n, i, j):


def biggest_meow_factor(n):
    top = math.sqrt(n) + 1
    highest_pos = 1
    bottom = 0
    while True:
        m = (bottom + top) / 2
        temp = math.pow(m, 9)
        if temp < n:
            top = m
            diff = (m - bottom) / 2
            m = bottom + diff
            highest_pos = max(highest_pos, helper(n, bottom, top))
        else:
            bottom = m
            diff = (top - m) / 2
            m = top - diff
            highest_pos = max(highest_pos, helper(n, bottom, top))
    return highest_pos