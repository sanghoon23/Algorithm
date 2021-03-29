#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PII pair<int, int>
#define MSIZE 1500000
PII Val[MSIZE + 60];
int N, Dp[MSIZE + 60];
int main()
{
	FASTIO;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> Val[i].first >> Val[i].second;

	for (int i = 1; i <= N + 1; ++i)
	{
		Dp[i] = max(Dp[i], Dp[i - 1]);
		Dp[i + Val[i].first] = max(Dp[i + Val[i].first], Dp[i] + Val[i].second);
	}

	int Answer = 0;
	for (int i = 1; i <= N + 1; ++i) Answer = max(Answer, Dp[i]);
	cout << Answer;
	return 0;
}

