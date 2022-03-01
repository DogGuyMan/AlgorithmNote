#include <iostream>
#include <algorithm>
using namespace std;

int N;
int DP[101010] = {
    0,
};

int fibo(int n)
{
    if (n <= 2)
    {
        return n == 2 ? 1 : n;
    }
    if (DP[n] != 0)
    {
        return DP[n];
    }
    return DP[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
    cin >> N;
    for (int i = 0; i <= N; i++)
    {
        cout << fibo(i) << '\n';
    }
}