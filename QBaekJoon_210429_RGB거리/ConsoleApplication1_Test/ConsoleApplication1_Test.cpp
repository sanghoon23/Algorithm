#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, Board[1001][4], Dp[2][4];
int main()
{
	FASTIO;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Board[i][1] >> Board[i][2] >> Board[i][3];
	}
	
	bool bRow = false;
	Dp[bRow][1] = Board[1][1];
	Dp[bRow][2] = Board[1][2];
	Dp[bRow][3] = Board[1][3];

	for (int i = 2; i <= N; ++i)
	{
		Dp[!bRow][1] = min(Dp[bRow][2] + Board[i][1], Dp[bRow][3] + Board[i][1]);
		Dp[!bRow][2] = min(Dp[bRow][1] + Board[i][2], Dp[bRow][3] + Board[i][2]);
		Dp[!bRow][3] = min(Dp[bRow][1] + Board[i][3], Dp[bRow][2] + Board[i][3]);
		bRow = !bRow;
	}
	cout << min(Dp[bRow][1], min(Dp[bRow][2], Dp[bRow][3]));
	return 0;
}

