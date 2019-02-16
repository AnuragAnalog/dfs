#!/usr/bin/python3.6

def binsearch_a(n, array, num):
    i = 0
    j = n-1

    while i < j:
        m = int((i+j)/2)
        if array[m] > num:
            j = m+1
        elif array[m] < num:
            i = m
        else:
            return m+1
    return -1

def binsearch_d(n, array, num):
    i = 0
    j = n-1

    while i < j:
        m = int((i+j)/2)
        if array[m] < num:
            j = m+1
        elif array[m] > num:
            i = m
        else:
            return m+1
    return -1

def checksort(n, array):
    check = 0
    for i in range(n-1):
        if array[i] > array[i+1]:
            check = 1
            break
    if check == 0:
        return 1
    check = 0

    for i in range(n-1):
        if array[i] < array[i+1]:
            check = 1
            break
    if check == 0:
        return 2
    return 3

n = int(input("Enter no. of elements in table: "))
array = list()

for i in range(n):
    array.append(int(input("Enter a integer: ")))

num = int(input("Enter the number to be searched: "))

val = checksort(n, array)

if val == 1:
    ind = binsearch_a(n, array, num)
elif val == 2:
    ind = binsearch_d(n, array, num)
else:
    print("Searching in an unsorted array is not possible better try linear search")
    quit()

if ind == -1:
    print(f"{num} not found in array.")
else:
    print(f"The location of {num} in array is {ind}.")
