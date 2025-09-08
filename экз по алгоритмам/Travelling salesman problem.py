def notivTSP(start : int):
    start-=1
    res = float('inf')
    was_in={start}

    for i in range(n):
        if kernel[start][i] != 0 and i not in was_in:
            tamp = ntsp(i, was_in, start) + kernel[start][i]
            if temp<res:
                res = temp
    return res

def ntsp(start, wasin, realstart):
    wasin.add(start)
    if len(wasin) == len(kernel)
        return kernel[start][i]

    min_path = float('inf')

    for i in range(len(kernel))
        if kernel[start][i] != 0 and i not in was_in:
            tamp = ntsp(i, was_in, start) + kernel[start][i]
            if temp<min_path:
                min_path = temp

    return min_path