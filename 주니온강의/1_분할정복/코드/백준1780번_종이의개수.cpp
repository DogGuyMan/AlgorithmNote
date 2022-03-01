#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const bool DEBUG = false;
int N;
int board[3000][3000] = { 0, };

map<string, int> paperCount = {
	{"-1" , 0},
	{"0" , 0},
	{"1" , 0}
};

string keytostr(int _index) {
	if (_index == -1)
		return "-1";
	if (_index == 0)
		return "0";
	if (_index == 1)
		return "1";
}


void printBoard(int _SZ, int _SR, int _SC) {
	int ER = _SR + _SZ;
	int EC = _SC + _SZ;
	for (int i = _SR; i < ER; i++) {
		for (int j = _SC; j < EC; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool IsFillBoard(int _SZ, int _SR, int _SC) {
	int ER = _SR + _SZ;
	int EC = _SC + _SZ;
	for (int i = _SR; i < ER; i++) {
		for (int j = _SC; j < EC; j++) {
			if (board[i][j] != board[_SR][_SC])
			{
				return false;
			}
		}
	}
	return true;
}

void countingPaper(int _SZ, int _SR, int _SC) {
	string curPaper = keytostr(board[_SR][_SC]);
	if (DEBUG) {
		printf("---%d %d ", _SR, _SC); cout << curPaper << '\n';
		printBoard(_SZ, _SR, _SC); cout << '\n';
	}
	if (IsFillBoard(_SZ, _SR, _SC)) {
		paperCount[curPaper]++;
		return;
	}
	else {
		for (int NewSR = 0; NewSR < _SZ; NewSR += (_SZ / 3)) {
			for (int NewSC = 0; NewSC < _SZ; NewSC += (_SZ / 3)) {
				countingPaper(_SZ / 3, _SR + NewSR, _SC+NewSC);
			}
		}
	}
	return;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	countingPaper(N, 0, 0);
	cout << paperCount["-1"] << '\n';
	cout << paperCount["0"] << '\n';
	cout << paperCount["1"] << '\n';
	return 0;
}
