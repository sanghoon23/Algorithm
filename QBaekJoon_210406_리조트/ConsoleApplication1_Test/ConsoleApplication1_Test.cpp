#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMAX 1e9

int N, M, NoneDay[101], Dp[101][40][40][201];

int Solve(int Day, int Y, int X, int Cup)
{
	if (Day > N) return 0;

	int& Ret = Dp[Day][Y][X][Cup];
	if (Ret != -1) return Ret;
	Ret = MMAX;

	if (NoneDay[Day]) Ret = min(Ret, Solve(Day + 1, Y, X, Cup));
	else
	{
		Ret = min(Ret, Solve(Day + 3, Y + 1, X, Cup + 1) + 25000);
		Ret = min(Ret, Solve(Day + 5, Y, X + 1, Cup + 2) + 37000);

		if (Cup >= 3) Ret = min(Ret, Solve(Day + 1, Y, X, Cup - 3));
		else Ret = min(Ret, Solve(Day + 1, Y, X, Cup) + 10000);
	}
	return Ret;
}

int main()
{
	FASTIO;
	memset(Dp, -1, sizeof(Dp));
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int Num; cin >> Num;
		NoneDay[Num] = 1;
	}
	int Answer = Solve(1, 0, 0, 0);
	if (Answer == MMAX) cout << 0;
	else cout << Answer;
	return 0;
}

