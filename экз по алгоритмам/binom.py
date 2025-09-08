def binom1(n: int):
    mass = [[1] for i in range(n+1)]
    for i in range(1,n+1):
        temp = [1 for i in range(i+1)]
        for j in range(1, i//2+1):
            temp[j] = mass[i-1][j-1] + mass[i-1][j]
            temp[i-j] = temp[j]
        mass[i] = temp
    return mass

print(binom1(5))















