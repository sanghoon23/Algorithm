#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMAX 1e9
int N, F, S, Total, Board[22], Dp[22][22][22];

int Solve(int Cnt, int L, int R)
{
	if (Cnt >= Total) return 0;

	int& Ret = Dp[Cnt][L][R];
	if (Ret != -1) return Ret;
	Ret = MMAX;

	int InLeft = abs(L - Board[Cnt]), InRight = abs(R - Board[Cnt]);
	Ret = min(Ret, Solve(Cnt + 1, Board[Cnt], R) + InLeft);
	Ret = min(Ret, Solve(Cnt + 1, L, Board[Cnt]) + InRight);
	return Ret;
}

int main()
{
	FASTIO;
	memset(Dp, -1, sizeof(Dp));
	cin >> N >> F >> S >> Total;
	for (int i = 0; i < Total; ++i) cin >> Board[i];
	
	cout << Solve(0, F, S);
	return 0;
}

