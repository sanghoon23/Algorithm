#include "pch.h"
#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000003
int N, K, Dp[1010][1010];
int main()
{
	FASTIO;
	cin >> N >> K;
	for (int i = 0; i <= N; ++i)
	{
		Dp[i][0] = 1;
		Dp[i][1] = i;
	}

	for (int j = 2; j <= N; ++j)
		for (int i = 2; i <= K; ++i)
			Dp[j][i] = (Dp[j - 1][i] + Dp[j - 2][i - 1]) % MOD;

	cout << (Dp[N - 1][K] + Dp[N - 3][K - 1]) % MOD;
	return 0;
}

