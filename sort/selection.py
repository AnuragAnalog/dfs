#!/usr/bin/python3.6

def selection_ascend(n, array):
    for i in range(n):
        tmp = array[i:]
        mini = min(tmp)
        ind = tmp.index(mini) + i
        array[i], array[ind] = array[ind], array[i]
    return ;

def selection_descend(n, array):
    for i in range(n):
        tmp = array[i:]
        maxi = max(tmp)
        ind = tmp.index(maxi) + i
        array[i], array[ind] = array[ind], array[i]
    return ;

n = int(input("Enter the total no. of elements: "))
array = list()

for i in range(n):
    array.append(int(input("Enter the integer: ")))

opt = int(input("Select an option:\n1) Ascending order\n2) Descending order\n"))

if opt == 1:
    selection_ascend(n, array)
else:
    selection_descend(n, array)
print("Sorted list: \n", array)
