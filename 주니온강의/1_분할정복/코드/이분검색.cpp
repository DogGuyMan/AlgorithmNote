#include <iostream>
using namespace std;
/*************************************
 *
 * 전역변수 설정
 *
 **************************************/
int arr[1010101] = {
    0,
}; // sorted
int N, X;

/*************************************
 *
 * 이분탐색 합수
 * >매개변수<
 *   1. _Low : 좌측 배열 "인덱스"
 *   2. _High : 우측 배열 "인덱스"
 *   3. _T : 찾으려는 "값"
 * >함수 지역변수<
 *   1. _Mid : 반띵된 배열 "인덱스"
 * >설명<
 * 1. _low는 _high보다 늘 작은(좌측) 인덱스 이다
 *
 * 2. _T 보다 작은 값, 같은값, 큰값을 통해 재귀호출
 *
 **************************************/
int binarySearch(int _Low, int _High, int _T)
{
    int _Mid = (_Low + _High) / 2;
    if (_Low > _High)
    {
        return -1;
    }

    if (_T == arr[_Mid])
    {
        return _Mid;
    }
    else if (_T > arr[_Mid])
    {
        return binarySearch(_Mid + 1, _High, _T);
    }
    else if (_T < arr[_Mid])
    {
        return binarySearch(_Low, _Mid - 1, _T);
    }
}
int main()
{
    /*************************************
     *
     * 입력받기
     *
     **************************************/
    cin >> N >> X;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    /*************************************
     *
     * 테스트 케이스
     *
     **************************************/
    cout << binarySearch(0, N, X) << '\n';
}