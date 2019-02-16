#!/usr/bin/python3.6

def ciltable(start, end, array):
    key = array[start]

    for i in range(start, end, -1):
        array[i] = array[i-1]
    array[end] = key
    return

def insertion_ascend(n, array):
    for i in range(n):
        ind = i
        for j in range(i+1):
            if array[ind] < array[j]:
                ciltable(ind, j, array)

    return ;

def insertion_descend(n, array):
    for i in range(n):
        ind = i
        for j in range(i+1):
            if array[ind] > array[j]:
                ciltable(ind, j, array)

    return ;

n = int(input("Enter the total no. of elements: "))
array = list()

for i in range(n):
    array.append(int(input("Enter the integer: ")))

opt = int(input("Select an option:\n1) Ascending order\n2) Descending order\n"))

if opt == 1:
    insertion_ascend(n, array)
else:
    insertion_descend(n, array)
print("Sorted list: \n", array)
