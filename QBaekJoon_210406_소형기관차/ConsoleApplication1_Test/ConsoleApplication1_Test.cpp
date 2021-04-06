#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, K, Board[50001], Sum[50001], Dp[3][50001];
int Solve(int Cnt, int X)
{
	if (Cnt == 3 || X >= N) return 0;

	int& Ret = Dp[Cnt][X];
	if (Ret != -1) return Ret;
	Ret = 0;
	//@ 왜 for 문을 쓰면 시간 초과인가?? 어디가 잘못되었나??
	//	for (int i = X + 1; ((3 - Cnt) * K) + i - 1 <= N; ++i)
	//	{
	//		Ret = max(Ret, Solve(Cnt + 1, i + K - 1) + Sum[i + K - 1] - Sum[i - 1]);
	//	}
	return Ret = max(Solve(Cnt + 1, X + K) + Sum[X + K] - Sum[X], Solve(Cnt, X + 1));
}

int main()
{
	FASTIO;
	memset(Dp, -1, sizeof(Dp));
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Board[i];
		Sum[i] = Sum[i - 1] + Board[i];
	}
	cin >> K;

	cout << Solve(0, 0);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//int N, K, Board[50001], Sum[50001], Dp[3][17000];
//int Solve(int Cnt, int X)
//{
//	if (Cnt == 3) return 0;
//
//	int& Ret = Dp[Cnt][X];
//	if (Ret != -1) return Ret;
//	Ret = 0;
//	for (int i = X + 1; ((3 - Cnt) * K) + i - 1 <= N; ++i)
//	{
//		Ret = max(Ret, Solve(Cnt + 1, i + K - 1) + Sum[i + K - 1] - Sum[i - 1]);
//	}
//	return Ret;
//}
//
//int main()
//{
//	FASTIO;
//	memset(Dp, -1, sizeof(Dp));
//	cin >> N;
//	for (int i = 1; i <= N; ++i)
//	{
//		cin >> Board[i];
//		Sum[i] = Sum[i - 1] + Board[i];
//	}
//	cin >> K;
//
//	cout << Solve(0, 0);
//	return 0;
//}

