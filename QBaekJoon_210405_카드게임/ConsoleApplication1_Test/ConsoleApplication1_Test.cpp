#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int T, N, Cost[1001], Dp[1001][1001];

int Solve(int Y, int X, bool bTurn)
{
	int& Ret = Dp[Y][X];
	if (Ret != -1) return Ret;

	Ret = 0;
	if (Y == X)
	{
		if (bTurn) return Ret = Cost[Y];
		return 0;
	}
	if (bTurn)
	{
		Ret = max(Ret, Solve(Y + 1, X, !bTurn) + Cost[Y]);
		Ret = max(Ret, Solve(Y, X - 1, !bTurn) + Cost[X]);
	}
	else
	{
		Ret = min(Solve(Y + 1, X, !bTurn), Solve(Y, X - 1, !bTurn));
	}
	return Ret;
}

int main()
{
	FASTIO;
	cin >> T;
	while (T--)
	{
		cin >> N;
		memset(Dp, -1, sizeof(Dp));
		for (int i = 1; i <= N; ++i) cin >> Cost[i];

		cout << Solve(1, N, true) << '\n';
	}
	return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////

//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//int T, N, Cost[1001], Dp[1001][1001];
//int main()
//{
//	FASTIO;
//	cin >> T;
//	while (T--)
//	{
//		cin >> N;
//		memset(Dp, 0, sizeof(Dp));
//		for (int i = 1; i <= N; ++i) cin >> Cost[i];
//
//		int Answer = 0;
//		Dp[1][0] = Cost[1]; Dp[0][1] = Cost[N];
//		for (int j = 1; j <= N; ++j)
//		{
//			for (int i = 1; i + j <= N; ++i)
//			{
//				if (i - 2 >= 0) Dp[j][i] = max(Dp[j][i], Dp[j][i - 2] + Cost[N - i + 1]);
//				if (j - 2 >= 0) Dp[j][i] = max(Dp[j][i], Dp[j - 2][i] + Cost[j]);
//				if (j - 1 >= 0 && i - 1 >= 0) Dp[j][i] = max(Dp[j][i], Dp[j - 1][i - 1] + max(Cost[j], Cost[N - i + 1]));
//
//				if ((j + i) % 2 == 1) Answer = max(Answer, Dp[j][i]);
//			}
//		}
//		cout << Answer << '\n';
//	}
//	return 0;
//}

