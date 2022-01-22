#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 123456789;
const int MIN = -123456789;
vector<int> V;

void insertion(vector<int> *_V, bool _order)
{
    int arraySize = V.size();
    //한쪽이 정렬되었다고 가정
    for (int target = 1; target < arraySize; target++)
    {
        int targetVal = V[target];
        int curIdx = target - 1;
        while (curIdx >= 0 && !(((V[curIdx] >= targetVal) ^ (_order))))
        {
            V[curIdx + 1] = V[curIdx];
            curIdx--;
        }
        V[curIdx + 1] = targetVal;
    }
}

void selection(vector<int> *_V, bool _order)
{
    int arraySize = V.size();
    for (int target = 0; target < arraySize - 1; target++)
    {
        int foundedindex = target;
        for (int curindex = target + 1; curindex < arraySize; curindex++)
        {
            //find MAX or MIN
            if (!(V[foundedindex] >= V[curindex]) ^ (_order))
            {
                foundedindex = curindex;
            }
        }
        int temp = V[target];
        V[target] = V[foundedindex];
        V[foundedindex] = temp;
    }
}

void bubble(vector<int> *_V, bool _order)
{
    int arraySize = V.size();
    for (int cycle = arraySize - 1; cycle >= 1; cycle--)
    {
        int swapCount = cycle; //카운트 숫자만큼만 swap 기회가있다
        for (int curindex = 0; curindex < swapCount; curindex++)
        {
            if (!((V[curindex] >= V[curindex + 1]) ^ (_order)))
            {
                //swap
                int temp = V[curindex];
                V[curindex] = V[curindex + 1];
                V[curindex + 1] = temp;
                //
            }
        }
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
    //bubble(&V, LESS);
    //selection(&V, LESS);
    insertion(&V, LESS);
    cout << "정렬된 데이터" << '\n';
    for (int i = 0; i < N; i++)
    {
        cout << V[i] << ' ';
    }
}
