#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMAX 1e9
int N, Dp[1000001];

int Solve(int N)
{
	if (N == 1) return 0;

	int& Ret = Dp[N];
	if (Ret != -1) return Ret;
	Ret = MMAX;

	Ret = min(Ret, Solve(N - 1) + 1);
	if(N >= 2) Ret = min(Ret, Solve(N / 2) + (N % 2) + 1);
	if(N >= 3) Ret = min(Ret, Solve(N / 3) + (N % 3) + 1);
	return Ret;
}

int main()
{
	FASTIO;
	memset(Dp, -1, sizeof(Dp));
	cin >> N;
	cout << Solve(N);
	return 0;
}

