#all sorts are smallest entry to largest entry
#bubble sort
def bubble_sort(arr):
    comparisons = 0
    swaps = 0
    for i in range(len(arr)):
        for z in range(len(arr)-i-1):
            comparisons += 1
            if arr[z] > arr[z+1]:
                temp = arr[z]
                arr[z] = arr[z+1]
                arr[z+1] = temp
                swaps += 1
    print(comparisons, swaps, sep = '\t')
    #print (arr)
    return comparisons, swaps

#selection sort
def selection_sort(arr):
    comparisons = 0
    swaps = 0
    for i in range(len(arr)-1):
        min = i
        for z in range(i+1, len(arr)):
            comparisons += 1
            #print(arr[z], arr[min])
            if arr[z] < arr[min]:
                min = z
        swaps += 1
        temp = arr[min]
        arr[min] = arr[i]
        arr[i] = temp
    print(comparisons, swaps, sep = '\t')
    #print(arr)
    return comparisons, swaps

#insertion sort
def insertion_sort(arr):
    comparisons = 0
    assignment = 0
    for i in range(1, len(arr)):
        key = arr[i]
        z = i-1
        #print(arr, ' original', i)
        while z >= 0:
            if(key < arr[z]):
                arr[z+1] = arr[z]
                z -= 1
                assignment += 1
                comparisons += 1
            else:
                comparisons += 1
                break
        arr[z+1] = key
        assignment += 1
    print(comparisons, assignment, sep = '\t')
    #print(arr)
    return comparisons, assignment

#merge sort
def merge_sort(arr):
    comparisons = 0
    if len(arr) > 1:
        mid = len(arr)//2
        left = arr[:mid]
        right = arr[mid:]
        i = j = k = 0
        comparisons += merge_sort(left)
        comparisons += merge_sort(right)
        while i < len(left) and j < len(right):
            comparisons += 1
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else: #left[i] > right[j]
                arr[k] = right[j]
                j += 1
            k += 1

        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1
        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1
    #print(comparisons)
    #print(arr)
    return comparisons

#main
array_size = int(input())
arr1 = [0] * (array_size)
for i in range(array_size):
    arr1[i] = int(input())
arr2 = arr1.copy()
arr3 = arr1.copy()
arr4 = arr1.copy()

(bubble_sort(arr1))
(selection_sort(arr2))
(insertion_sort(arr3))
print(merge_sort(arr4))