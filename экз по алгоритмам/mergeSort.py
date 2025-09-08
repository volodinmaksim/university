def mergeSort(mass: list):
    if len(mass)< 2:
        return mass

    first = mergeSort(mass[:len(mass)/2])
    second = mergeSort(mass[len(mass)/2+1:])
    return merge(first, second)

def merge(first: list, second: list):
    res = []
    i = j = 0
    while i < len(first) and j < len(second):
        if first[i] > second[j]:
            res.append(first[i])
            i += 1
        else:
            res.append(second[j])
            j += 1

    while i < len(first):
        res.append(first[i])
        i += 1

    while j < len(second):
        res.append(second[j])
        j += 1

    return res