#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, M, Dp[1001][1001];
int main()
{
	FASTIO;
	cin >> N >> M;
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < M; ++i)
			cin >> Dp[j][i];

	for(int j = 0; j < N; ++j)
		for (int i = 0; i < M; ++i)
		{
			int Val = Dp[j][i];
			if(j - 1 >= 0) Dp[j][i] = max(Dp[j][i], Dp[j - 1][i] + Val);
			if(i - 1 >= 0) Dp[j][i] = max(Dp[j][i], Dp[j][i - 1] + Val);
			if(j - 1 >= 0 && i - 1 >= 0) Dp[j][i] = max(Dp[j][i], Dp[j - 1][i - 1] + Val);

		}

	cout << Dp[N - 1][M - 1];
	return 0;
}

