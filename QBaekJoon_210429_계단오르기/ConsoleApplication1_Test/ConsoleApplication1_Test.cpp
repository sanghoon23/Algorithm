#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>

//@반복적 DP
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMIN -1e9
int N, Board[301], Dp[301][3];

int main()
{
	FASTIO;
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> Board[i];

	Dp[1][1] = Board[1];
	Dp[2][1] = Board[2];

	for (int j = 2; j <= N; ++j)
	{
		Dp[j][1] = max(Dp[j - 2][1] + Board[j], Dp[j - 2][2] + Board[j]);
		Dp[j][2] = max(Dp[j][2], Dp[j - 1][1] + Board[j]);
	}

	cout << max(Dp[N][1], Dp[N][2]);
	return 0;
}

///////////////////////////////////////////////////////////////////////////
//@재귀

//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define MMIN -1e9
//int N, Board[301], Dp[301][3];
//
//int Solve(int Curr, int Continu)
//{
//	if (Curr > N || Continu >= 3) return MMIN;
//	if (Curr == N) return Board[N];
//
//	int& Ret = Dp[Curr][Continu];
//	if (Ret != -1) return Ret;
//	Ret = 0;
//
//	Ret = max(Ret, Solve(Curr + 1, Continu + 1) + Board[Curr]);
//	Ret = max(Ret, (Solve(Curr + 2, 1) + Board[Curr]));
//	return Ret;
//}
//
//int main()
//{
//	FASTIO;
//	memset(Dp, -1, sizeof(Dp));
//	cin >> N;
//	for (int i = 1; i <= N; ++i) cin >> Board[i];
//
//	cout << Solve(0, 0);
//	return 0;
//}

