def solve(N, X, S):
    location = 0
    while(location <= N and S[location] != X):
        location += 1
        if(location > N):
            location = -1
    return location
