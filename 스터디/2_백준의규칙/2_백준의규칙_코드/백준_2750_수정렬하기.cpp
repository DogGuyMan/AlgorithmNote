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
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        V.push_back(input);
    }
    //bubble(&V, 1);
    //selection(&V, 1);
    insertion(V, 1);
    for (int i = 0; i < N; i++)
    {
        cout << V[i] << '\n';
    }
}