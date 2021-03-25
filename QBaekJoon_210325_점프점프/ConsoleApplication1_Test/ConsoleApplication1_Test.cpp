#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMAX 987654321
int N, Val[1011], Dp[1011];
int main()
{
	FASTIO;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		Dp[i] = MMAX;
		cin >> Val[i];
	}
	if (N == 1) { cout << 0; exit(0); }
	if (Val[1] > 0) Dp[1] = 0;
	for (int j = 1; j <= N; ++j)
		for (int i = j + Val[j]; i > j; --i)
			if (Dp[j] != MMAX) Dp[i] = min(Dp[i], Dp[j] + 1);

	if (Dp[N] == MMAX) cout << -1;
	else cout << Dp[N];
	return 0;
}

