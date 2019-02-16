#!/usr/bin/python3.6

def linsearch(n, array, num):
    for i in range(n):
        if array[i] == num:
            return i+1
    return -1

n = int(input("Enter no. of elements in table: "))
array = list()

for i in range(n):
    array.append(int(input("Enter a integer: ")))

num = int(input("Enter the number to be searched: "))
ind = linsearch(n, array, num)

if ind == -1:
    print(f"{num} not found in array.")
else:
    print(f"The location of {num} in array is {ind}.")
