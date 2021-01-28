#include "pch.h"
#include <iostream>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define LL long long
#define MOD 10007
int N;
LL Dp[1001][10];
LL Solve(int Idx, int Num)
{
	if (Idx >= N) return 1;
	LL& Ret = Dp[Idx][Num];
	if (Ret != -1) return Ret;
	Ret = 0;
	for (int k = 0; k <= 9; ++k)
		if (Num <= k) Ret += (Solve(Idx + 1, k) % MOD);

	return Ret % MOD;
}

int main()
{
	FASTIO;
	cin >> N;
	memset(Dp, -1, sizeof(Dp));
	cout << Solve(0, 0) % MOD << '\n';
	return 0;
}

