#include "pch.h"
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MMAX = 1e10;
int N = 0, Dp[1000001];
int Solve(int Val)
{
	if (Val == 1) return 0;
	if (Val < 1) return MMAX;

	if (Dp[Val] != -1) return Dp[Val];
	Dp[Val] = MMAX;

	Dp[Val] = Solve(Val - 1) + 1;
	if (Val % 2 == 0) Dp[Val] = min(Dp[Val], Solve(Val / 2) + 1);
	if (Val % 3 == 0) Dp[Val] = min(Dp[Val], Solve(Val / 3) + 1);
	return Dp[Val];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(Dp, -1, sizeof(Dp));
	cin >> N;
	cout << Solve(N);
	return 0;
}

