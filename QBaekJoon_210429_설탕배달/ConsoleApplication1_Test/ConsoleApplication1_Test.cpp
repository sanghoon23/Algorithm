#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMAX 1e9
int N, Dp[5001];
int main()
{
	FASTIO;
	cin >> N;
	fill(Dp, Dp + 5001, MMAX);

	for (int j = 0; j <= 2000; ++j)
	{
		for (int i = 0; i <= 1100; ++i)
		{
			if (j * 3 + i * 5 > N) continue;
			Dp[j * 3 + i * 5] = min(Dp[j * 3 + i * 5], j + i);
		}
	}

	if (Dp[N] == MMAX) cout << -1;
	else cout << Dp[N];
	return 0;
}

