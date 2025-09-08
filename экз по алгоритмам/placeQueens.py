def WeCanPlase(n,ng,nh):
    pass

def placeQueens(now_row: int, mass: list, n: int):
    if n == now_row:
        return True

    for cal in range(n):
        if WeCanPlase(cal, now_row, mass):
            mass[now_row] = cal

            if placeQueens(now_row+1, mass, n):
                return True

    return False

