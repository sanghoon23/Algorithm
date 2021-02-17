#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 100001
int T, N, Board[2][MSIZE], Dp[2][MSIZE];

int Solve(int Y, int X)
{
	if (X >= N) return 0;

	int& Ret = Dp[Y][X];
	if (Ret != -1) return Ret;
	Ret = 0;
	Ret = max(Ret, Solve(!Y, X + 1) + Board[Y][X]); //@찢었다면
	Ret = max(Ret, Solve(Y, X + 1)); //@안했다면
	return Ret;
}

int main()
{
	FASTIO;
	cin >> T;
	while (T--)
	{
		cin >> N;
		memset(Dp, -1, sizeof(Dp));
		for (int j = 0; j < 2; ++j)
			for (int i = 0; i < N; ++i)
				cin >> Board[j][i];

		cout << max(Solve(0, 0), Solve(1, 0)) << '\n';
	}
	return 0;
}

