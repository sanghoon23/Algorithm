#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int N = 0, Board[100001], Dp[100001];
int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> Board[i];

	Dp[1] = Board[1];
	Dp[2] = max(Board[2], Board[1] + Board[2]);
	for (int i = 3; i <= N; ++i)
		Dp[i] = max(Dp[i - 1], max(Dp[i - 3] + Board[i - 1] + Board[i], Dp[i - 2] + Board[i]));
	cout << Dp[N];
	return 0;
}

