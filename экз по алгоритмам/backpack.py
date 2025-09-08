def backpack(index: int, W: int, N: int, mass: list, w_now, c_now):
    if w_now > W:
        return  0
    if index == N:
        return c_now

    take = 0
    if w_now + mass[index][0] <= W:
        take = backpack(index+1, W, N, mass, w_now + mass[index][0], c_now + mass[index][1])

    skip = backpack(index+1, W, N, mass, w_now, c_now)

    return max(skip, take)

