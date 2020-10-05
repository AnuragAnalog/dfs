#!/usr/bin/python3

import numpy as np
from itertools import permutations

def is_sorted(n, array, asc=True):
    if asc:
        for i in range(n-1):
            if array[i] > array[i+1]:
                return False
    else:
        for i in range(n-1):
            if array[i] < array[i+1]:
                return False
    return True

def bogo_ascend(n, array):
    permut = permutations([i for i in range(n)], n)
    for seq in permut:
        tmp = np.array(array)
        if is_sorted(n, tmp[list(seq)], asc=True):
            return tmp[list(seq)]
    return

def bogo_descend(n, array):
    permut = permutations([i for i in range(n)], n)
    for seq in permut:
        tmp = np.array(array)
        if is_sorted(n, tmp[list(seq)], asc=False):
            return tmp[list(seq)]
    return

n = int(input("Enter the total no. of elements: "))
array = list()

for i in range(n):
    array.append(int(input("Enter the integer: ")))

opt = int(input("Select an option:\n1) Ascending order\n2) Descending order\n"))

if opt == 1:
    array = bogo_ascend(n, array)
else:
    array = bogo_descend(n, array)
print("Sorted list: \n", array)

