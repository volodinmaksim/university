# задача выбора.
# суть задачи в нахождении k-го по величине(и подомного) элемента в неотсортированном массиве.
# нахождение медианы более интересный случай для k=n//2.
# сортировать не эффективно -> нужен алгоритм который нам поможет найти этот элемент.
# алгоритм заключается в разделении элементов на две части по опорному и рекурсивного вызова
# для подходящей части пока наш опорный не будет k-ый по величине #

def partition(arr: list, start: int, end: int):
    j: int = start+1
    for i in range(start+1, end+1):
        if arr[i] < arr[start]:
            arr[i], arr[j] = arr[j], arr[i]
            j+=1
    arr[j-1],arr[start] = arr[start],arr[j-1]
    return arr, j-1

def FindMedian(arr:list, k: int):
    return findmedian(arr, 0, len(arr)-1, k)

def findmedian(arr:list, start: int, end: int, k: int):
    arr, j = partition(arr, 0, len(arr)-1)
    if j == k:
        return arr[j]
    elif k < j:
        arr, j = findmedian(arr, start, j-1, k)
    else:
        arr, j = findmedian(arr, j+1, end, k)

# эффективность алгоритма С(n)=С(n/2)+ n+1 по теореме ровна O(n)
# в худшем случае O(n)#
