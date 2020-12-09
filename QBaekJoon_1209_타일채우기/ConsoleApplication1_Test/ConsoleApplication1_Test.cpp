#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
int N = 0;
int Dp[31] = { 0, };
int main()
{
	cin >> N;
	Dp[0] = 1;
	Dp[2] = 3;
	for (int k = 4; k <= N; ++k)
	{
		Dp[k] += Dp[k - 2] * 3;
		for (int j = 4; j <= k; j += 2)
			Dp[k] += Dp[k - j] * 2;
	}
	cout << Dp[N];
	return 0;
}

