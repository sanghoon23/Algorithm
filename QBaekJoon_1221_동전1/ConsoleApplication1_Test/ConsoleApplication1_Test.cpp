#include "pch.h"
#include <iostream>

using namespace std;
int N = 0, K = 0, Input[101], Dp[100001];
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> Input[i];

	Dp[0] = 1;
	for (int i = 0; i < N; ++i)
		for (int j = Input[i]; j <= K; ++j)
			Dp[j] += Dp[j - Input[i]];

	cout << Dp[K] << endl;
	return 0;
}

