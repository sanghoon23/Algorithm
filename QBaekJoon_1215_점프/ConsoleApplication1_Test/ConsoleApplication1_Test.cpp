#include "pch.h"
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int N = 0, Board[101][101];
long long Dp[101][101];
long long Solve(int Y, int X)
{
	if (Y == N - 1 && X == N - 1) return 1;
	if (Y < 0 || Y >= N || X < 0 || X >= N || Board[Y][X] == 0) return 0;

	long long& Ret = Dp[Y][X];
	if (Ret != -1) return Dp[Y][X];
	Ret = 0;
	return Ret = Solve(Y + Board[Y][X], X) + Solve(Y, X + Board[Y][X]);
}

int main()
{
	memset(Dp, -1, sizeof(Dp));
	cin >> N;
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < N; ++i)
			cin >> Board[j][i];
	cout << Solve(0, 0);
	return 0;
}

