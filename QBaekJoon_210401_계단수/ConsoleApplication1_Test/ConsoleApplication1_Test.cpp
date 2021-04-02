#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000000
int N, Dp[101][10][1 << 10];

bool Check(int V)
{
	if (V == (1 << 10) - 1) return true;
	return false;
}

int Solve(int Y, int X, int V)
{
	if (Y == N)
	{
		if (Check(V)) return 1;
		return 0;
	}

	int& Ret = Dp[Y][X][V];
	if (Ret != -1) return Ret;
	Ret = 0;
	int F = V | (1 << (X - 1)), S =  V | (1 << (X + 1));
	if(X - 1 >= 0) Ret += Solve(Y + 1, X - 1, F) % MOD;
	if(X + 1 <= 9) Ret += Solve(Y + 1, X + 1, S) % MOD;
	Ret %= MOD;
	return Ret;
}

int main()
{
	FASTIO;
	cin >> N;

	int Answer = 0;
	for (int i = 1; i <= 9; ++i)
	{
		memset(Dp, -1, sizeof(Dp));
		Answer += Solve(1, i, (1 << i));
		Answer %= MOD;
	}
	cout << Answer;
	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////
//@차공

//#define MOD 1000000000
//int N, Dp[101][101][101];
//int Solve(int Y, int X, int C, vector<bool> Visited)
//{
//	if (Y == N)
//	{
//		if (C == 10) return 1;
//		return 0;
//	}
//
//	int& Ret = Dp[Y][X][C];
//	if (Ret != -1) return Ret;
//	Ret = 0;
//	if (X - 1 >= 0)
//	{
//		vector<bool> Insert = Visited;
//		if (Insert[X - 1] == false)
//		{
//			Insert[X - 1] = true;
//			Ret += Solve(Y + 1, X - 1, C + 1, Insert) % MOD;
//		}
//		else Ret += Solve(Y + 1, X - 1, C, Insert) % MOD;
//	}
//	if (X + 1 <= 9)
//	{
//		vector<bool> Insert = Visited;
//		if (Insert[X + 1] == false)
//		{
//			Insert[X + 1] = true;
//			Ret += Solve(Y + 1, X + 1, C + 1, Insert) % MOD;
//		}
//		else Ret += Solve(Y + 1, X + 1, C, Insert) % MOD;
//	}
//	return Ret % MOD;
//}
//
//int main()
//{
//	FASTIO;
//	cin >> N;
//	int Answer = 0;
//	for (int i = 1; i <= 9; ++i)
//	{
//		vector<bool> Visited(10, false);
//		Visited[i] = true;
//		memset(Dp, -1, sizeof(Dp));
//		Answer += Solve(1, i, 1, Visited) % MOD;
//	}
//
//	cout << Answer % MOD;
//	return 0;
//}

