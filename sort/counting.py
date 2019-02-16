#!/usr/bin/python3.6

def counting_ascend(n, array):
    maxi = max(array)
    mini = min(array)
    tmparr = [0 for i in range(maxi+1)]

    for i in range(n):
        tmparr[array[i]] += 1

    print("Sorted list:")
    for i in range(mini, maxi+1):
        if tmparr[i] == 0:
            continue
        elif tmparr[i] == 1:
            print(str(i)+" ")
        else:
            for j in range(tmparr[i]):
                print(str(i)+" ")

    return ;

def counting_descend(n, array):
    maxi = max(array)
    mini = min(array)
    tmparr = [0 for i in range(maxi+1)]

    for i in range(n):
        tmparr[array[i]] += 1

    print("Sorted list:")
    for i in range(maxi, mini+1, -1):
        if tmparr[i] == 0:
            continue
        elif tmparr[i] == 1:
            print(str(i)+" ")
        else:
            for j in range(tmparr[i]):
                print(str(i)+" ")

    return ;

n = int(input("Enter the total no. of elements: "))
array = list()

for i in range(n):
    array.append(int(input("Enter the integer: ")))

opt = int(input("Select an option:\n1) Ascending order\n2) Descending order\n"))

if opt == 1:
    counting_ascend(n, array)
else:
    counting_descend(n, array)
