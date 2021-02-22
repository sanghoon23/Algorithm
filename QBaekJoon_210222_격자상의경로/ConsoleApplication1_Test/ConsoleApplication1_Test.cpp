#include "pch.h"
#include <iostream>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define LL long long
int N, M, K;
LL Dp[16][16];

LL Solve(int Y, int X, int N, int M)
{
	if (Y > N || X > M) return 0;
	if (Y == N && X == M) return 1;
	LL& Ret = Dp[Y][X];
	if (Ret != -1) return Ret;

	Ret = 0;
	Ret += Solve(Y + 1, X, N, M);
	Ret += Solve(Y, X + 1, N, M);
	return Ret;
}

int main()
{
	FASTIO;
	memset(Dp, -1, sizeof(Dp));
	cin >> N >> M >> K;
	int F = 0, S = 0;
	if (K > M)
	{
		F = (K % M != 0) ? (K / M) + 1 : (K / M);
		S = (K % M != 0) ? K % M : M;
	}
	else F = 1, S = K;

	if(K == 0 || N == 1 || M == 1) cout << Solve(1, 1, N, M);
	else cout << Solve(1, 1, F, S) * Solve(F, S, N, M);
	return 0;
}

