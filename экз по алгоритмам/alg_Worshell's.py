def wor(a: list):
    for i in range(len(a)):
        for j in range(len(a)):
            for k in range(len(a)):
                if a[i][j] == a[j][k] == 1:
                    a[i][k] = 1