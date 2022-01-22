#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> V;
/***************************************************************
 * 
 * 
 * 
***************************************************************/

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

/***************************************************************
 * 
 * 
 * 
***************************************************************/

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

/***************************************************************
 * 
 * 
 * 
***************************************************************/

void bubble(vector<int> *_V, bool _order)
{
    //바쁘게 음직일것은 뭘까?
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
    insertion(&V, 1);
    for (int i = 0; i < N; i++)
    {
        cout << V[i] << '\n';
    }
}