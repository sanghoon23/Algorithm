#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
int N = 0, Board[501][501], Dp[501][501][4];
pair<int, int> Dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int Solve(int Y, int X, int D, int Val)
{
	int& Ret = Dp[Y][X][D];
	if (Ret != -1) return Ret;

	Ret = 1;
	for (int i = 0; i < 4; ++i)
	{
		int YY = Y + Dir[i].first, XX = X + Dir[i].second;
		if (YY < 0 || YY >= N || XX < 0 || XX >= N) continue;
		if (Board[YY][XX] > Val)
		{
			Ret = max(Ret, Solve(YY, XX, i, Board[YY][XX]) + 1);
		}
	}
	return Ret;
}
int main()
{
	cin >> N;
	memset(Dp, -1, sizeof(Dp));
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < N; ++i)
			cin >> Board[j][i];

	int Answer = 0;
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < N; ++i)
			Answer = max(Answer, Solve(j, i, 0, Board[j][i]));

	cout << Answer;
	return 0;
}

