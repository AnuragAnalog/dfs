#!/usr/bin/python3.6

def bubble_ascend(n, array):
    for i in range(n):
        for j in range(n-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return ;

def bubble_descend(n, array):
    for i in range(n):
        for j in range(n-i-1):
            if array[j] < array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return ;

n = int(input("Enter the total no. of elements: "))
array = list()

for i in range(n):
    array.append(int(input("Enter the integer: ")))

asc = int(input("Select an option:\n1) Ascending order\n2) Descending order\n"))

if asc == 1:
    bubble_ascend(n, array)
elif asc == 2:
    bubble_descend(n, array)
else:
    print("Invalid Option")
print("Sorted list: \n", array)
