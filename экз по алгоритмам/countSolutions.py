def WeCanPlase(n, ng, nh):
    pass


def countSolutions(now_row: int, mass: list, n: int, count: int):
    if now_row == n:
        count+=1
        return count

    for col in range(n):
        if WeCanPlase(col, now_row, mass):
            mass[now_row] = col
            count = countSolutions(now_row+1, mass, n, count)

    return count

