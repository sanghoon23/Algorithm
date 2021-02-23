#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, S, M, Board[101], Dp[101][100001];
int Solve(int Idx, int Curr)
{
	if (Curr < 0 || Curr > M) return -10000;
	if (Idx == N + 1) return Curr;

	int& Ret = Dp[Idx][Curr];
	if (Ret != -1) return Ret;

	Ret = max(Solve(Idx + 1, Curr + Board[Idx]), Solve(Idx + 1, Curr - Board[Idx]));
	return Ret;
}

int main()
{
	FASTIO;
	cin >> N >> S >> M;
	memset(Dp, -1, sizeof(Dp));
	for (int i = 1; i <= N ; ++i)
		cin >> Board[i];

	Solve(0, S);
	if (Dp[0][S] == -10000) cout << -1;
	else cout << Dp[0][S];
	return 0;
}

