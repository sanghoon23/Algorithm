#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int D, K, Dp[31];
int main()
{
	FASTIO;
	Dp[1] = 1; Dp[2] = 2;
	for (int i = 3; i <= 30; ++i) Dp[i] = Dp[i - 1] + Dp[i - 2];
	cin >> D >> K;

	int X = Dp[D - 3], Y = Dp[D - 2];
	if (D == 3) X = Y = 1;
	int A = 1, B = 1;
	while (1)
	{
		int Total = K;
		Total -= X * A;
		if (Total % Y == 0)
		{
			B = Total / Y;
			break;
		}
		++A;
	}
	cout << A << '\n';
	cout << B << '\n';
	return 0;
}

