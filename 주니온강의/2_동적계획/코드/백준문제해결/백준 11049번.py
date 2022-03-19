import sys
DEBUFOP = False;

INF = 1 << 31

def MatMul(_A) : 
    M = [[0] * (N+1) for _ in range(N+1)]
    # 주대각 DP 초기화
    for DIA in range(1,N) : 
        for i in range(1, N - DIA + 1) : 
            j = i + DIA
            M[i][j] = INF
            # 대각선을 기준으로 DP 
            for k in range(i,j):
                val = M[i][k] + M[k+1][j] #여태 서브 행렬의 최소 수
                val += _A[i-1][0] * _A[k][0] * _A[j-1][1]
                if(M[i][j] > val) :
                    M[i][j] = val
    return M[1][N]

#입력
N = int(sys.stdin.readline())
A = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

if(DEBUFOP) :
    for i in range(len(A)):
        print(A[i][0], A[i][1])

print(MatMul(A))

"""
import sys
input = sys.stdin.readline

N = int(input())

A = []
for _ in range(N):
    a, b = map(int, input().split())
    A.append(a)
A.append(b)

min_mult = [ [0]*(N+1) for _ in range(N+1) ]

for i in range(N, -1, -1):
    for j in range(i+2, N+1):
        min_mult[i][j] = min([A[i]*A[k]*A[j] + min_mult[i][k] + min_mult[k][j] for k in range(i+1, j)])

print(min_mult[0][N])
"""