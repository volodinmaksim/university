def appointments(index: int, c_now: int, n: int, mass: list, jobs: list):
    if n==index:
        return c_now
    min_cost=float("inf")
    for i in range(n):
        if not jobs[i]:
            jobs[i] = True
            c = appointments(index+1, c_now + mass[index][i], n, mass, jobs)
            min_cost = min(c, min_cost)
            jobs[i] = False
    return min_cost

