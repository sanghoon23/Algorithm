#include "pch.h"
#include <iostream>
using namespace std;
long long T = 0, N = 0, Dp[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };
int main()
{
	cin >> T;
	for (int i = 11; i <= 101; ++i)
		Dp[i] = Dp[i - 1] + Dp[i - 5];

	while (T--)
	{
		cin >> N;
		cout << Dp[N] << '\n';
	}
	return 0;
}

