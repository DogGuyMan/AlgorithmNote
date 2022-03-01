########################
""""
이분탐색 합수
>매개변수<
  1. _S : 리스트
  2. _low : 좌측 배열 "인덱스"
  3. _high : 우측 배열 "인덱스"
  4. _target : 찾으려는 "값"
>함수 지역변수<
  1. mid : 반띵된 배열 "인덱스"
>설명<
1. _low는 _high보다 늘 작은(좌측) 인덱스 이다
2. target보다 작은 값, 같은값, 큰값을 통해 재귀호출
"""
########################


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

########################
#
# 입력받기
#
########################


N = int(input())
A = list(map(int, input().split()))
A.sort()
M = int(input())
X = list(map(int, input().split()))

########################
#
# 테스트
#
########################

for target in X:
    if(BinarySearch(A, 0, N-1, target) != -1):
        print(1)
    else:
        print(0)
