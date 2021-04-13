#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, Board[1001], Dp[1001];

int Solve(int Cnt)
{
	int& Ret = Dp[Cnt];
	if (Ret != -1) return Ret;
	Ret = Board[Cnt];
	int Sum = 0;
	for (int j = Cnt + 1; j <= N; ++j)
		if (Board[Cnt] < Board[j]) Sum = max(Sum, Solve(j));

	return Ret += Sum;
}

int main()
{
	FASTIO;
	memset(Dp, -1, sizeof(Dp));
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> Board[i];

	cout << Solve(0);
	return 0;
}

