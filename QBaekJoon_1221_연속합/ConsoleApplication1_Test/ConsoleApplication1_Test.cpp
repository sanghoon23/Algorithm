#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;
int N = 0, Val[100001], Dp[100001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> Val[i];

	int Answer = -1e9;
	for (int i = 1; i <= N; ++i)
	{
		if (Dp[i - 1] + Val[i] > 0 && Dp[i - 1] > 0) Dp[i] = Dp[i - 1] + Val[i];
		else Dp[i] = Val[i];

		Answer = max(Answer, Dp[i]);
	}

	cout << Answer;
	return 0;
}

