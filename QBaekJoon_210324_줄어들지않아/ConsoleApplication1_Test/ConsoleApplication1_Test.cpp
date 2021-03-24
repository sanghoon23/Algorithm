#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define LL long long
LL T, N, Calc[10], Dp[70];
int main()
{
	FASTIO;
	for (int k = 0; k <= 9; ++k) Calc[k] = 10 - k;
	Dp[1] = 10; Dp[2] = 55;
	for (int j = 3; j <= 64; ++j)
	{
		LL Sum = 0;
		for (int i = 0; i <= 9; ++i)
		{
			LL CC = 0;
			for (int k = i; k <= 9; ++k)
			{
				CC += Calc[k];
			}
			Calc[i] = CC;
			Sum += CC;
		}
		Dp[j] = Sum;
	}

	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << Dp[N] << '\n';
	}
	return 0;
}

