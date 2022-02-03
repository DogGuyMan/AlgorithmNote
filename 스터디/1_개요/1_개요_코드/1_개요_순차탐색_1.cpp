#include <iostream>
using namespace std;
int arr[1010101] = {
    0,
};
int N, X;
int main()
{
    cin >> N >> X;
    int location = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == X)
        {
            location = i;
            break;
        }
    }
    cout << location << '\n';
}
/// https://modoocode.com/261