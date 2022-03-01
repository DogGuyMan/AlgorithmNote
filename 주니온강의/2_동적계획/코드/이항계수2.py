from sqlite3 import paramstyle


n = int(input())

mid = n // 2
# 2차원 배열 만드는것은 가로는 딱 알맞게 숫자 사용하면됨
# for문은 end-1 까지만 표시
pasTree = [[0] * (mid + 1) for _ in range(n + 1)]

# print(pasTree)


def printTree():
    for i in range(n + 1):
        print("%d :" % i, end=" ")
        for j in range(min(i, mid) + 1):
            print(Choice(i, j), end=" ")
        print()


def Choice(n, k):
    if(mid + 1 < k):
        k = n - k
    if(k == 0 or k == n):
        pasTree[n][k] = 1
        return pasTree[n][k]
    if(k == 1 or k == n-1):
        pasTree[n][k] = n
        return pasTree[n][k]
    if(pasTree[n][k] != 0):
        return pasTree[n][k]
    for i in range(n + 1):
        for j in range(2, min(i, mid) + 1):
            pasTree[i][j] = pasTree[i-1][j-1] + pasTree[i-1][j]
    return pasTree[n][k]


printTree()
