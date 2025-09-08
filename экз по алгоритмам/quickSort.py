def partition(start: int, end: int, mass: list):
    j = start
    temp = mass[end]
    for i in range(start, end):
        if mass[i] < temp:
            mass[i], mass[j] = mass[j], mass[i]
            j+=1

    mass[j], mass[end] =  mass[end], mass[j]
    return mass, j


def quick_sort(start: int, end: int, mass: list):
    if start < end:
        mass, s = partition(start, end, mass)
        mass = quick_sort(start, end, mass)
        mass = quick_sort(start, end, mass)

    return mass