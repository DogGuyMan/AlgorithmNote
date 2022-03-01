n = int(input())
# input
midSz = n // 2
pascalTree = [[0] * n for _ in range(n+1)]


def Cho(n, k):
    if(pascalTree[n][k] != 0):
        return pascalTree[n][k]
    if(k == 0 or k == n):
        pascalTree[n][k] = 1
        return pascalTree[n][k]
    if(k == 1 or k == n-1):
        pascalTree[n][k] = n
        return pascalTree[n][k]
    for i in range(0, n + 1):
        for j in range(min(i, k) + 1):
            if(not(j == 0 or j == i)):
                pascalTree[i][j] = pascalTree[i-1][j-1] + pascalTree[i-1][j]
    return pascalTree[n][k]


for i in range(n):
    for j in range(i + 1):
        print(Cho(i, j), end=" ")
    print()
