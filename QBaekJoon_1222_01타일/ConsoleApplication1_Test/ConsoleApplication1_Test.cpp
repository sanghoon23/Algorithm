#include "pch.h"
#include <iostream>
using namespace std;
#define MOD 15746
int N = 0, Dp[1000001];
int main()
{
	cin >> N;
	Dp[1] = 1; Dp[2] = 2;
	for (int i = 3; i <= N; ++i)
		Dp[i] = (Dp[i - 1] + Dp[i - 2]) % MOD;
	cout << Dp[N];
	return 0;
}

