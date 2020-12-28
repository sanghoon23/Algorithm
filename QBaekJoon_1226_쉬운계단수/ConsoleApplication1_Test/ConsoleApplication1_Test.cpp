#include "pch.h"
#include <iostream>
#define MOD 1000000000
using namespace std;
int N = 0, Dp[101][10];
int main()
{
	cin >> N;
	Dp[0][0] = 0; Dp[1][0] = 1;
	Dp[0][1] = 1; Dp[1][1] = 1;
	Dp[0][9] = 1; Dp[1][9] = 1;
	for (int i = 2; i <= 8; ++i)
	{
		Dp[0][i] = 1; Dp[1][i] = 2;
	}

	for (int j = 2; j <= N; ++j)
	{
		for (int i = 0; i <= 9; ++i)
		{
			if (i == 0) Dp[j][i] = Dp[j - 1][i + 1] % MOD;
			else if (i == 9) Dp[j][i] = Dp[j - 1][i - 1] % MOD;
			else Dp[j][i] = (Dp[j - 1][i - 1] + Dp[j - 1][i + 1]) % MOD;
		}
	}

	long long Answer = 0;
	for (int i = 0; i <= 9; ++i)
		Answer += Dp[N - 1][i];
	cout << Answer % MOD;
	return 0;
}

