from random import randrange


N = int(input())

# 얼마나 음직였는지 숫자
DP = [0 for _ in range(N+1)]
DP[1] = 1
DP[0] = -999
# 음직인 경로
moveList = list()


def hanoiCount(_n):
    if _n == 1:
        return DP[1]
    for i in range(2, _n + 1):
        DP[i] = 2 * DP[i-1] + 1
    return DP[_n]


def hanoi(_n, _from, _to, _by):
    if _n == 1:
        moveList.append({_from, _to})
    else:
        hanoi(_n-1, _from, _by, _to)
        moveList.append({_from, _to})
        hanoi(_n-1, _by, _to, _from)


hanoiCount(N)
print(DP[N])

hanoi(N, 1, 3, 2)
print(len(moveList))
