#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*************************************************
 *
 * n.
 *  >매개 변수<
 *  >지역 변수<
 *  >함수 설명<
 *
 *************************************************/

/*************************************************
 *
 * 1. 벡터 내부 원소 전부 출력하는 함수
 *
 *************************************************/
void PRINT_V(string str, vector<int> &_V)
{
    cout << str << '\n';
    for (int E : _V)
        cout << E << ' ' << '\n';
    cout << '\n';
}
/*************************************************
 *
 * 2. 오름차순 내림차순 결정하는 compare함수
 *  A <= B는 오름차순
 *  A > B는 내림차순
 *
 *************************************************/
bool COMP(int A, int B)
{
    return A <= B;
}

int Partition(int _S, int _E, vector<int> &_V)
{
    int Pval = _V[_S]; //피봇 값
    int L = _S + 1;    // low가 되어야한다 _S는 피봇이라 선택하면 안됨
    int HP = _E;       // high가 되면서 피봇이랑 바뀌어야할 인덱스
    while (L <= HP)
    {
        while (_V[L] < Pval)
        {
            L++;
        }
        while (_V[HP] > Pval)
        {
            HP--;
        }
        //적절한 L과 HP 찾아야 된다.
        if (L <= HP)
        {
            swap(_V[L], _V[HP]);
        }
    }
    int Pidx = HP;
    swap(_V[Pidx], _V[_S]);
    return Pidx;
}

void QuickSort(int _S, int _E, vector<int> &_V)
{
    if (_S < _E)
    {
        int P = Partition(_S, _E, _V);
        QuickSort(_S, P - 1, _V);
        QuickSort(P + 1, _E, _V);
    }
}

void swap(int *A, int *B)
{
    int temp = *B;
    *B = *A;
    *A = temp;
}

int main()
{
    vector<int> V = {26, 5, 37, 1, 61, 11, 59, 15, 48, 19};
    PRINT_V("Before", V);
    QuickSort(0, V.size() - 1, V);
    PRINT_V("After", V);
}