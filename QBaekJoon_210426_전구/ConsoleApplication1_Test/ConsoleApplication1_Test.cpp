#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMAX 1e9
int N, K, Board[201], Dp[201][201];

int Solve(int L, int R)
{
	if (L >= R) return 0;

	int& Ret = Dp[L][R];
	if (Ret != -1) return Ret;
	Ret = MMAX;

	for (int i = L; i < R; ++i)
	{
		int Tmp = (Board[L] == Board[i + 1]) ? 0 : 1;
		Ret = min(Ret, Solve(L, i) + Solve(i + 1, R) + Tmp);
	}
	return Ret;
}

int main()
{
	FASTIO;
	memset(Dp, -1, sizeof(Dp));
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) cin >> Board[i];

	cout << Solve(1, N) << '\n';
	return 0;
}

