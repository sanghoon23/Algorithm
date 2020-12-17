#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N = 0, Input = 0, Dp[1000001], Result = 0;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Input;
		Dp[Input] = 1;
		if (Dp[Input - 1] != 0)
		{
			Dp[Input] = Dp[Input - 1] + 1;
			Result = max(Result, Dp[Input]);
		}
	}
	cout << N - Result;
	return 0;
}

