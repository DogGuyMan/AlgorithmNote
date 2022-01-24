#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 123456789;
const int MIN = -123456789;
vector<int> V;

void swap(int *_left, int *_right)
{
    int temp = *_left;
    *_left = *_right;
    *_right = temp;
}

void bubble(vector<int> &_V, bool _order)
{
    int arraySize = _V.size();
    for (int target = arraySize - 1; target > 0; target--)
    {
        for (int swapLeft = 0; swapLeft < target; swapLeft++)
        {
            if (!((_V[swapLeft] >= _V[swapLeft + 1]) ^ (_order)))
            {
                swap(_V[swapLeft], _V[swapLeft + 1]);
            }
        }
    }
}

void selection(vector<int> &_V, bool _order)
{
    int arraySize = _V.size();
    for (int target = 0; target < arraySize; target++)
    {
        int foundedIndex = target;
        for (int curidx = arraySize - 1; curidx >= target; curidx--)
        {
            if (!((_V[foundedIndex] >= _V[curidx]) ^ (_order)))
            {
                foundedIndex = curidx;
            }
        }
        swap(_V[foundedIndex], _V[target]);
    }
}

void insertion(vector<int> &_V, bool _order)
{
    int arraySize = _V.size();
    for (int target = 1; target < arraySize; target++)
    {
        int targetBuff = _V[target];
        int curidx = target - 1;
        while (curidx >= 0 && !((_V[curidx] >= targetBuff) ^ _order))
        {
            _V[curidx + 1] = _V[curidx];
            curidx--;
        }
        _V[curidx + 1] = targetBuff;
    }
}

int main()
{
    srand(time(NULL));
    cout << "정렬할 데이터 크기를 말해주세여 (숫자는 랜덤생성입니다.)" << '\n';
    int N;
    cin >> N;

    cout << "오름차순이 True(1) 인지 내림차순 False(0)인지 말해주세요" << '\n';
    bool LESS;
    cin >> LESS;

    cout << "데이터 생성" << '\n';
    for (int i = 0; i < N; i++)
    {
        V.push_back(rand() % 1000);
        cout << V.back() << ' ';
    }
    cout << '\n';
    //bubble(V, LESS);
    selection(V, LESS);
    //insertion(V, LESS);
    cout << "정렬된 데이터" << '\n';
    for (int i = 0; i < N; i++)
    {
        cout << V[i] << ' ';
    }
}
