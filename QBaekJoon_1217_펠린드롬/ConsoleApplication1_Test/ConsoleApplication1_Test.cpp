#include "pch.h"
#include <iostream>
int N = 0, Board[2001], Dp[2001][2001], M = 0, S = 0, E = 0;
int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0);
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		Dp[i][i] = 1;
		scanf("%d", &Board[i]);
	}

	for (int j = 1; j < N; ++j)
	{
		for (int i = 1; i + j <= N; ++i)
		{
			if (Board[i] == Board[i + j] && j == 1) { Dp[i][i + j] = 1; continue; }
			if (Board[i] == Board[i + j] && Dp[i + 1][i + j - 1] == 1)
				Dp[i][i + j] = 1;
		}
	}

	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &S, &E);
		printf("%d\n", Dp[S][E]);
	}
	return 0;
}

