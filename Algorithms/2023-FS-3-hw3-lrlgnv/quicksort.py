#Logan Lorts
# 12/8/2023

#bubble sort
def BubbleSort(arr):
    swaps = 0
    for i in range(len(arr)):
        for z in range(len(arr)-1):
            if arr[z] > arr[z+1]:
                temp = arr[z]
                arr[z] = arr[z+1]
                arr[z+1] = temp
                swaps += 1
    #print (arr)
    return swaps

#partition
def partition(a, l, r):
    swaps = 0
    pivot = a[l]
    i = l
    j = r
    while i < j:
        while i < j and a[i] <= pivot:
            i = i + 1
        while a[j] > pivot:
            j = j -  1
        a[i], a[j] = a[j], a[i]
        swaps += 1
    a[i], a[j] = a[j], a[i]
    swaps += 1
    a[l], a[j] = a[j], a[l]
    swaps += 1
    return j, swaps

#quick sort
def QuickSort(arr, l, r):
    swaps = 0
    swap = 0
    if l < r:
        p, swap = partition(arr, l, r)
        swaps += swap
        swaps += QuickSort(arr, l, p-1)
        swaps += QuickSort(arr, p+1, r)
    return swaps

#main
array_size = int(input())
arr = [0] * (array_size)
for i in range(array_size):
    arr[i] = int(input())
arr1 = arr.copy()
arr2 = arr.copy()
#print('output')
print(BubbleSort(arr1))
print(QuickSort(arr2, 0, array_size-1))
