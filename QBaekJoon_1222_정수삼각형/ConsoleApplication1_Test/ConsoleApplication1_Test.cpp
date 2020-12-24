#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;
int Height = 0, Board[501][501], Dp[501][501];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> Height;
	for (int i = 1; i <= Height; ++i)
		for (int j = 0; j < i; ++j)
			cin >> Board[i][j];

	for (int i = 1; i <= Height; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (j <= i - 1)
				Dp[i][j] = max(Dp[i][j], Dp[i - 1][j] + Board[i][j]);
			
			if(i - 1 >= 0 && j - 1 >= 0)
				Dp[i][j] = max(Dp[i][j], Dp[i - 1][j - 1] + Board[i][j]);
		}
	}

	int Answer = 0;
	for (int i = 1; i <= Height; ++i)
		Answer = max(Answer, Dp[Height][i]);

	cout << Answer;
	return 0;
}

