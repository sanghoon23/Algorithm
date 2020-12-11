#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
#define MOD 9901
int N = 0;
int Dp[100001][3] = { 0, };

int main()
{
	cin >> N;
	
	Dp[0][0] = Dp[0][1] = Dp[0][2] = 1;
	for (int j = 1; j < N; ++j)
	{
		Dp[j][0] = (Dp[j - 1][0] + Dp[j - 1][1] + Dp[j - 1][2]) % MOD;
		Dp[j][1] = (Dp[j - 1][0] + Dp[j - 1][2]) % MOD;
		Dp[j][2] = (Dp[j - 1][0] + Dp[j - 1][1]) % MOD;
	}
	cout << ((Dp[N - 1][0]) + (Dp[N - 1][1]) + (Dp[N - 1][2])) % MOD;
	return 0;
}

