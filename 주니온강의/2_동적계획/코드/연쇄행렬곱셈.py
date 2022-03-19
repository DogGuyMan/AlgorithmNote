from numpy import Inf

#D는 행 하나 열 n 개 길이
#diagonal은 행렬개수 n-1이다
#M[i][j] i부터 j까지 행렬 곱의 최소값
    # 사실 최종 알아랴하는것은 M[1][N] 이간하다
#P어디 포인트에서 최적적인 행렬인지 곱셈순서 저장
    # 재귀호출 분할 정복

def miniNum (M, d, i, j) :
    minVal = Inf
    minK = 0
    for k in range(i, j):
        value = M[i][k] + M[k+1][j]
        value += d[i-1] * d[k] * d[j]
        if(minVal > value) :
            minVal = value
            minK = k
    return minVal, minK

def minmult (d):
    n = len(d) - 1 # 주대각행렬은 어차핀 0이므로 1부터 의미가 있음 
    M = [[-1]* (n + 1) for _ in range(n+1)]     # 인덱스에서 n-1까지면 안된다
    P = [[-1] * (n + 1) for _ in range(n+1)]    # 인덱스 n 까지 해야한다.
    for i in range(1, n+1):
        M[i][i] = 0 # 주대각 0
    for diagonal in range(1, n):
        for i in range (1, n-diagonal+1):
            j = i + diagonal
            M[i][j], P[i][j] = miniNum(M,d,i,j)
    return M, P

def order(P, i, j):
    if(i == j) :
        print(f"A{i}", end=" ")
    else :
        k = P[i][j]
        print("(", end=' ')
        order(P, i, k)
        order(P, k + 1, j)
        print(")", end=' ')

def compairFor (n) :
    for i in range(1, n) :
        print(i, end=' ')
    print()
    for i in range(0, n) :
        print(i, end=' ')
    print()
    for i in range(n) :
        print(i, end=' ')
    print()
    # range(n)은 개수는 n
    # 단, 인덱스는 n-1 까지
    P = [[-1] * (n + 1) for _ in range(n+1)]

    print(len(P))
    print(len(P[0]))

INF = 999
d = [5,2,3,4,6,7,8]
M, P = minmult(d)
print("M =  ")
for i in range(1, len(M)):
    print(M[i][1:])

print("P =  ")
for i in range(1, len(P)):
    print(P[i][1:]) #배열 한줄 출력

print('minimum order : ', end=" ")
order(P, 1, len(d) -1)