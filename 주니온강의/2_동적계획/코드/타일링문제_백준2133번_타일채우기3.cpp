#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 1e6 + 1;
const int MOD = 1000000007;

ll DP[MAX][2] = {
    {0, 0},
};
ll N;

ll F_DP(ll _N)
{
    if (DP[_N][0] != 0)
        return DP[_N][0];
    for (int i = 3; i <= _N; i++)
    {
        DP[i][0] = (DP[i - 1][0] * 2 + DP[i - 2][0] * 3) % MOD;
        DP[i][1] = (DP[i - 1][1] + (DP[i - 3][0] * 2)) % MOD;
        DP[i][0] = (DP[i][0] + DP[i][1]) % MOD;
    }
    return DP[_N][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    DP[0][0] = 0;
    DP[1][0] = 2;
    DP[2][0] = 7;
    DP[2][1] = 2;
    cin >> N;
    cout << F_DP(N) << '\n';
    return 0;
}
