#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

const bool DEBUG = false;

void swap(int *x, int *y)
{
    if (x != y)
    {
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}

typedef struct RC
{
    int row;
    int col;
} RC;

int N;

RC X;
int board[256][256] = {
    0,
};
int TrominoNum = 0;

void printBoard(int _N)
{
    int SZ = 1 << _N;
    for (int i = SZ - 1; i >= 0; i--)
    {
        for (int j = 0; j < SZ; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void FillCenterExcept(RC _Mid, int _part)
{
    TrominoNum++;
    if (_part != 0)
    {
        board[_Mid.row - 1][_Mid.col - 1] = TrominoNum;
    }
    if (_part != 1)
    {
        board[_Mid.row - 1][_Mid.col] = TrominoNum;
    }
    if (_part != 2)
    {
        board[_Mid.row][_Mid.col - 1] = TrominoNum;
    }
    if (_part != 3)
    {
        board[_Mid.row][_Mid.col] = TrominoNum;
    }
}

void Tromino(int _N, RC _S, RC _X)
{
    int SZ = 1 << _N;
    if (SZ < 2)
    {
        return;
    }
    else
    {
        RC mid = {_S.row + (SZ >> 1), _S.col + (SZ >> 1)};
        RC part[4];
        part[0].row = mid.row - 1;
        part[0].col = mid.col - 1;
        part[1].row = mid.row - 1;
        part[1].col = mid.col;
        part[2].row = mid.row;
        part[2].col = mid.col - 1;
        part[3].row = mid.row;
        part[3].col = mid.col;

        if (_X.row < mid.row && _X.col < mid.col)
        {
            FillCenterExcept(mid, 0);
            part[0].row = _X.row;
            part[0].col = _X.col;
        }
        else if (_X.row < mid.row && _X.col >= mid.col)
        {
            FillCenterExcept(mid, 1);
            part[1].row = _X.row;
            part[1].col = _X.col;
        }
        else if (_X.row >= mid.row && _X.col < mid.col)
        {
            FillCenterExcept(mid, 2);
            part[2].row = _X.row;
            part[2].col = _X.col;
        }
        else if (_X.row >= mid.row && _X.col >= mid.col)
        {
            FillCenterExcept(mid, 3);
            part[3].row = _X.row;
            part[3].col = _X.col;
        }
        if (DEBUG)
        {
            printBoard(N);
            cout << '\n';
        }
        Tromino(_N - 1, {_S.row, _S.col}, part[0]);
        Tromino(_N - 1, {_S.row, mid.col}, part[1]);
        Tromino(_N - 1, {mid.row, _S.col}, part[2]);
        Tromino(_N - 1, {mid.row, mid.col}, part[3]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> X.row >> X.col;
    swap(X.row, X.col);
    board[--X.row][--X.col] = -1;
    if (DEBUG)
        printBoard(N);
    Tromino(N, {0, 0}, X);
    printBoard(N);
    return 0;
}
