#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, Cost[501], Dp[501];
vector<int> Board[501];

int Solve(int Idx)
{
	int& Ret = Dp[Idx];
	if (Ret != -1) return Ret;

	Ret = Cost[Idx];
	int MMax = 0;
	for (int Next : Board[Idx])
		MMax = max(MMax, Solve(Next));

	return Ret += MMax;
}

int main()
{
	FASTIO;
	memset(Dp, -1, sizeof(Dp));
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Cost[i];
		while (1)
		{
			int Input = 0; cin >> Input;
			if (Input == -1) break;
			Board[i].push_back(Input);
		}
	}
	for (int i = 1; i <= N; ++i) if(Dp[i] == -1) Solve(i);
	for (int i = 1; i <= N; ++i) cout << Dp[i] << '\n';
	return 0;
}

