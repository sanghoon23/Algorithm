#include "pch.h"
#include <iostream>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define LL long long
LL N, Dp[32][32];
int main()
{
	FASTIO;
	Dp[0][0] = 1;
	for (int j = 0; j <= 31; ++j) Dp[j][0] = 1;

	for (int j = 1; j <= 30; ++j)
		for (int i = 1; i <= j; ++i)
			Dp[j][i] = Dp[j - 1][i] + Dp[j][i - 1];

	while (1)
	{
		cin >> N;
		if (N == 0) break;
		cout << Dp[N][N] << '\n';
	}
	return 0;
}

