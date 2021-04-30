#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000
int N, Dp[1001][2][3];

int Solve(int Cnt, int L, int A)
{
	if (L >= 2) return 0;
	if (A >= 3) return 0;
	if (Cnt >= N) return 1;

	int& Ret = Dp[Cnt][L][A];
	if (Ret != -1) return Ret;
	Ret = 0;
	Ret += Solve(Cnt + 1, L, 0) % MOD;
	Ret += Solve(Cnt + 1, L + 1, 0) % MOD;
	Ret += Solve(Cnt + 1, L, A + 1) % MOD;
	return Ret %= MOD;
}

int main()
{
	FASTIO;
	memset(Dp, -1, sizeof(Dp));
	cin >> N;
	cout << Solve(0, 0, 0);
	return 0;
}

