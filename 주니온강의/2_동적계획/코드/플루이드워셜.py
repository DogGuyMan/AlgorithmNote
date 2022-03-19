def printM(M, P) :
    for index in range(len(M)) :
        print(f'{index} 정점 : {M[index]}')

def floyd(_W) :
    D = _W
    N = len(_W)
    P = [[-1] * N for _ in range(N)]

    for k in range(N) :
        for i in range(N):
            for j in range(N):
                if(D[i][j] > (D[i][k] + D[k][j])):
                    D[i][j] = D[i][k] + D[k][j]
                    P[i][j] = k

    return D, P

def path(P, u, v) :
    if(P[u][v] != -1) :
        path(P, u, P[u][v])
        print(f'v{P[u][v]}', end="-> ")
        path(P,P[u][v], v)

INF = 999;
W =[
    [0,1,INF,1,5],
    [9,0,3,2,INF],
    [INF,INF,0,4,INF],
    [INF,INF,2,0,3],
    [3, INF, INF, INF, 0],
]

D, P = floyd(W)
printM(D, P)

u = 4; v = 2
print(f'v{u}', end="-> ")
path(P, 4, 2)
print(f'v{v}', end=" ")