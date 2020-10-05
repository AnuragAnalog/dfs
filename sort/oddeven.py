#!/usr/bin/python3.6

def oddeven_ascend(n, array):
    check = 0

    while check == 0:
        check = 1
        for i in range(1, n-1, 2):
            if array[i] > array[i+1]:
                array[i], array[i+1] = array[i+1], array[i]
                check = 0
        for i in range(0, n-1, 2):
            if array[i] > array[i+1]:
                array[i], array[i+1] = array[i+1], array[i]
                check = 0

    return

def oddeven_descend(n, array):
    check = 0

    while check == 0:
        check = 1
        for i in range(1, n, 2):
            if array[i] < array[i+1]:
                array[i], array[i+1] = array[i+1], array[i]
                check = 0
        for i in range(0, n, 2):
            if array[i] < array[i+1]:
                array[i], array[i+1] = array[i+1], array[i]
                check = 0

    return

n = int(input("Enter the total no. of elements: "))
array = list()

for i in range(n):
    array.append(int(input("Enter the integer: ")))

asc = int(input("Select an option:\n1) Ascending order\n2) Descending order\n"))

if asc == 1:
    oddeven_ascend(n, array)
elif asc == 2:
    oddeven_descend(n, array)
else:
    print("Invalid Option")
print("Sorted list: \n", array)
