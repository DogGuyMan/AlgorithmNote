#include <stdio.h>

int 등차수열의합(int _N, int _D, int _init)
{
    return (((_init * 2) + _D * (_N - 1)) * _N) / 2;
}

int main()
{
    int arr[3];
    //순서대로 N :크기 D : 공차 init : 초기값
    for (int i = 0; i < 3; i++)
    {
        scanf_s("%d", &arr[i], sizeof(int));
    }
    printf("%d", 등차수열의합(arr[0], arr[1], arr[2]));
}