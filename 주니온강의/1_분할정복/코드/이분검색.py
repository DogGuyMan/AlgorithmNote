def BinarySearch(_S, _low, _high, _target):
    if(_low > _high):
        return -1
    else:
        mid = (_low + _high) // 2  # 몫 연산자를 꼭 기억하자!
        if(_S[mid] == _target):
            return mid
        elif(_S[mid] > _target):
            return BinarySearch(_S, _low, mid-1, _target)
        else:
            return BinarySearch(_S, mid+1, _high, _target)


N = int(input())
A = list(map(int, input().split()))
A.sort()
M = int(input())
X = list(map(int, input().split()))

for target in X:
    if(BinarySearch(A, 0, N-1, target) != -1):
        print(1)
    else:
        print(0)
