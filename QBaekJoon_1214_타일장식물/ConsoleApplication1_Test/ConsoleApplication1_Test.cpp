#include "pch.h"
#include <iostream>
using namespace std;
int N = 0;
long long Dp[81] = { 0, };
int main()
{
	cin >> N;
	Dp[1] = 1;
	Dp[2] = 1;
	for (int i = 3; i <= N; ++i)
		Dp[i] = Dp[i - 1] + Dp[i - 2];

	cout << (Dp[N] * 2) + (Dp[N - 1] + Dp[N]) * 2;
	return 0;
}

