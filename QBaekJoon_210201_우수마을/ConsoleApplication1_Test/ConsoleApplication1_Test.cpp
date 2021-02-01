#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 10001
int N, Dp[MSIZE][2], Weight[MSIZE];
vector<int> Board[MSIZE];
bool Visited[MSIZE];

void Solve(int Idx)
{
	Visited[Idx] = true;
	Dp[Idx][0] = 0;
	Dp[Idx][1] = Weight[Idx];
	for (int Next : Board[Idx])
	{
		if (Visited[Next] == false)
		{
			Solve(Next);
			Dp[Idx][0] += max(Dp[Next][0], Dp[Next][1]);
			Dp[Idx][1] += Dp[Next][0];
		}
	}
}

int main()
{
	FASTIO;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> Weight[i];

	for (int i = 0; i < N - 1; ++i)
	{
		int F, S;
		cin >> F >> S;
		Board[F].push_back(S);
		Board[S].push_back(F);
	}
	Solve(1);
	cout << max(Dp[1][0], Dp[1][1]) << '\n';
	return 0;
}

