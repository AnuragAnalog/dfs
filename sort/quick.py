#!/usr/bin/python3.6

def quick_ascend(start, end, array):
    if end > start:
        pivot = partition_a(array, start, end)
        quick_ascend(start, pivot-1, array)
        quick_ascend(pivot+1, end, array)

    return

def quick_descend(start, end, array):
   if end > start:
        pivot = partition_d(array, start, end)
        quick_descend(start, pivot-1, array)
        quick_descend(pivot+1, end, array)

   return

def partition_a(array, low, high):
    left = low
    right = high
    pivot_item = array[low]

    while left < right:
        while array[left] <= pivot_item:
            left = left + 1
        while array[right] > pivot_item:
            right = right - 1
        if left < right:
            array[left], array[right] = array[right], array[left]

    array[low] = array[right]
    array[right] = pivot_item

    return right

def partition_d(array, low, high):
    left = low
    right = high
    pivot_item = array[low]

    while left < right:
        while array[left] >= pivot_item:
            left = left + 1
        while array[right] < pivot_item:
            right = right - 1
        if left < right:
            array[left], array[right] = array[right], array[left]

    array[low] = array[right]
    array[right] = pivot_item

    return right

start = 0
n = int(input("Enter the total no. of elements: "))
array = list()

for i in range(n):
    array.append(int(input("Enter the integer: ")))

opt = int(input("Select an option:\n1) Ascending order\n2) Descending order\n"))

if opt == 1:
    quick_ascend(start, n-1, array)
else:
    quick_descend(start, n-1, array)
print("Sorted array: ", array)
