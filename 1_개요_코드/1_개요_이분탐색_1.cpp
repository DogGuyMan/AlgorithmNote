#include <iostream>
using namespace std;
int arr[1010101] = {
    0,
}; //sorted
int N, X;
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
    cin >> N >> X;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << binarySearch(0, N, X) << '\n';
}