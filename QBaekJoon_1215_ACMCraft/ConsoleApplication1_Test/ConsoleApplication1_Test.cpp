#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
const int MMIX = -1e9;
int T = 0, N = 0, K = 0, P = 0;
vector<int> BuildTime, Seq[1001], Answer;
int Dp[1001] = { 0, };
int Solve(int P)
{
	int& Ret = Dp[P];
	if (Ret != -1) return Ret;

	Ret = BuildTime[P];
	int M = MMIX;
	for (int i = 0; i < Seq[P].size(); ++i)
	{
		M = max(M, Solve(Seq[P][i]));
	}
	if (M == MMIX) return Ret;
	return Ret = Ret + M;
}

int main()
{
	cin >> T;
	for (int u = 0; u < T; ++u)
	{
		cin >> N >> K;

		fill(Dp, Dp + 1001, -1);
		BuildTime.clear();
		BuildTime.resize(N + 1);
		for (int i = 1; i <= N; ++i)
		{
			Seq[i].clear();
			cin >> BuildTime[i];
		}

		for (int i = 0; i < K; ++i)
		{
			int F = 0, S = 0;
			cin >> F >> S;
			Seq[S].push_back(F);
		}
		cin >> P;
		Answer.push_back(Solve(P));
	}

	for (int k = 0; k < Answer.size(); ++k)
		cout << Answer[k] << endl;

	return 0;
}

