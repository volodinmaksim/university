def binary_search(mass: list, elem: int):
    start = 0
    end = len(mass)-1
    mid = (end + start)//2
    while start <= end:
        if mid == elem:
            return True
        if mid < elem:
            start = mid + 1
            mid = (end + start)/2
        else:
            end = mid - 1
            mid = (end + start) // 2
    return False


def binary_recurse(mass: list, elem: int, left: int, right: int):
    if left >= right:
        return False
    mid = (left + right)//2
    if mid == elem:
        return True
    if mid < elem:
        return binary_recurse(mass, elem, mid+1, right)
    else:
        return binary_recurse(mass, elem, left, mid-1)