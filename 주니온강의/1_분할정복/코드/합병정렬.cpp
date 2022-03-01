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
/*************************************************
 *
 * 3. Conquer
 *  >매개 변수<
 *      1. _Start : 제일 좌측 인덱스
 *      2. _End :  제일 우측 인덱스
 *      3. _V : 정렬할 벡터 (call by reference)
 *  >지역 변수<
 *      1. _Temp : 임시로 배열을 담을 버퍼 벡터
 *      2. i : _Start 부터 시작해 _Mid 까지 그룹 A 처리
 *      3. j : _Mid+1 부터 시작해 _End 까지 그룹 B 처리
 *  1. 한그룹이 처리되지 않은 상황
 *      비교하면서 어느거 먼저 넣을지 결정
 *      Temp에 삽입
 *  2. 한그룹이 모두 처리된 상황
 *      남아있는그룹 전부 Temp삽입
 *  3. Temp에 있는 (정렬된 배열 결과) 를 원래 벡터에 덮어 씌우기
 *
 *************************************************/
void Conquer(int _Start, int _Mid, int _End, vector<int> &_V)
{
    vector<int> Temp;
    int i = _Start, j = _Mid + 1;
    while (i <= _Mid && j <= _End)
    {
        if (COMP(_V[i], _V[j]))
            Temp.push_back(_V[i++]);
        else
            Temp.push_back(_V[j++]);
    }
    if (i <= _Mid)
        while (i <= _Mid)
            Temp.push_back(_V[i++]);
    else
        while (j <= _End)
            Temp.push_back(_V[j++]);
    for (int E : Temp)
        _V[_Start++] = E;
}
/*************************************************
 *
 * 4. Divide
 *  >매개 변수<
 *      1. _Start : 제일 좌측 인덱스
 *      2. _End :  제일 우측 인덱스
 *      3. _V : 참조에 의한 호출(call by reference) 으로 벡터 불러오기
 *  >지역 변수<
 *      1. Mid : 반띵한 인덱스
 *           이것을 기준으로 Divide한다
 *  총 Divide를 두번 거쳐
 *      그룹A : _Start부터 Mid
 *      그룹B : Mid + 1 부터 _End까지
 *      ㄴ두 A , B그룹 각각에서만큼은 정렬되게 한다
 *  한번의 Conquer을 통해 두 그룹을 통합(Merge) 다른의미로 정복하자
 *
 *************************************************/
void Divide(int _Start, int _End, vector<int> &_V)
{
    if (_Start < _End)
    {
        int Mid = (_Start + _End) / 2;
        Divide(_Start, Mid, _V);
        Divide(Mid + 1, _End, _V);
        Conquer(_Start, Mid, _End, _V);
    }
}
/*************************************************
 *
 * 5. 머지소트 시작
 *  Divide & Conquer로 진행될것이다.
 *  첫 Divide의 시작을 알리는 의미에서
 *      0 ~ 벡터사이즈를 이용
 *
 *************************************************/
void MergeSort(vector<int> &_V)
{
    Divide(0, _V.size() - 1, _V);
}

int main()
{
    /*************************************************
     *
     * 입력설정
     *
     *************************************************/
    vector<int> V = {27, 10, 12, 20, 25, 13, 15, 22};
    PRINT_V("Before", V);
    MergeSort(V);
    PRINT_V("After", V);
    return 0;
}