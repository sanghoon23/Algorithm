#include "pch.h"
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int N = 0, Dp[501][501], F = 0, S = 0;
pair<int, int> Board[501];
int main()
{
	memset(Dp, 0, sizeof(Dp));
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> F >> S;
		Board[i + 1] = { F, S };
	}

	for (int j = 1; j < N; ++j)
	{
		for (int i = 1; i + j <= N; ++i)
		{
			if (j == 1) { Dp[i][i + j] = Board[i].first * Board[i + j].first * Board[i + j].second; continue; }
			Dp[i][i + j] = 2e9;
			for (int k = i; k + 1 <= i + j; ++k)
			{
				Dp[i][i + j] = min(Dp[i][i + j], Dp[i][k] + Dp[k + 1][i + j] + (Board[i].first * Board[k + 1].first * Board[i + j].second));
			}
		}
	}
	cout << Dp[1][N];
	return 0;
}

