#include <iostream>
#include <algorithm>
using namespace std;
int N;
int DP[10101] = {
    0,
};

int F_DP(int _N)
{
    if (_N == 0)
    {
        return DP[_N] = 1;
    }
    if (_N == 1)
    {
        return DP[_N] = 0;
    }
    if (_N == 2)
    {
        return DP[_N] = 3;
    }
    if (DP[_N] != 0)
    {
        return DP[_N];
    }
    DP[_N] = 3 * F_DP(_N - 2);
    for (int i = 3; i <= _N; i++)
    {
        if (i % 2 == 0)
        {
            DP[_N] += 2 * F_DP(_N - i);
        }
    }
    return DP[_N];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cout << F_DP(N) << '\n';
    return 0;
}