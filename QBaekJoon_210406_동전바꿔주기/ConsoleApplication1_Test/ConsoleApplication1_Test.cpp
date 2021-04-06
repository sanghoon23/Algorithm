#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int T, K, Num, Cnt, Dp[10001];
int main()
{
	FASTIO;
	memset(Dp, 0, sizeof(Dp));
	Dp[0] = 1;
	cin >> T >> K;
	for (int s = 0; s < K; ++s)
	{
		cin >> Num >> Cnt;
		for (int j = T; j >= 1; --j)
			for (int i = 1; i <= Cnt; ++i)
				if(j - Num * i >= 0) Dp[j] += Dp[j - Num * i];
	}
	cout << Dp[T];
	return 0;
}

///////////////////////////////////////////////////////////////////

//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//int T, K, Board[101][1001], Dp[101][10000];
//int main()
//{
//	FASTIO;
//	memset(Dp, 0, sizeof(Dp));
//	cin >> T >> K;
//	int Answer = 0;
//	for (int j = 1; j <= K; ++j)
//	{
//		int Num, Cnt;
//		cin >> Num >> Cnt;
//		for (int i = 1; i <= Cnt; ++i)
//		{
//			Dp[j][i] = Num * i;
//			if (Num * i == T) ++Answer;
//		}
//	}
//
//	for (int j = 1; j <= 100; ++j)
//	{
//		for (int i = 1; i <= 1000; ++i)
//		{
//			if (Dp[j][i] == 0) continue;
//			for (int r = 1; r <= 100; ++r)
//			{
//				if (j == r) continue;
//				for (int s = 1; s <= 1000; ++s)
//				{
//					if ((Dp[j][i] + Dp[r][s]) == T)
//						++Answer;
//				}
//			}
//		}
//	}
//	cout << Answer;
//	return 0;
//}

//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//int T, K, Dp[10001][10001];
//int main()
//{
//	FASTIO;
//	memset(Dp, 0, sizeof(Dp));
//	cin >> T >> K;
//	for (int j = 1; j <= K; ++j)
//	{
//		int Num, Cnt;
//		cin >> Num >> Cnt;
//		for (int i = 1; i <= Cnt; ++i)
//		{
//			if(Num * i <= T) ++Dp[i][Num * i];
//		}
//	}
//
//	for (int j = 1; j <= 10000; ++j)
//	{
//		for (int i = 1; i <= T; ++i)
//		{
//			if (Dp[j][i] == 0) continue;
//			for (int k = i + 1; k <= T; ++k)
//			{
//				if (Dp[j][k] && i + k <= T) ++Dp[j + j][i + k];
//			}
//		}
//	}
//	int Answer = 0;
//	for (int i = 1; i <= 10000; ++i)
//		Answer += Dp[i][T];
//
//	cout << Answer;
//		return 0;
//}

/////////////////////////////////////////////////////////////////////////////

//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define PII pair<int ,int>
//
//int T, K, Dp[101][1001][10000];
//PII Cost[101];
//
//int Solve(int Y, int X, int Cnt)
//{
//	if (Cnt == T) return 1;
//	if (Y > K) return 0;
//
//	int& Ret = Dp[Y][X][Cnt];
//	if (Ret != -1) return Ret;
//	Ret = 0;
//	for (int j = X + 1; j <= Cost[Y].second; ++j)
//		Ret += Solve(Y, j, Cnt + Cost[Y].first);
//
//	Ret += Solve(Y + 1, 0, Cnt);
//	return Ret;
//}
//
//int main()
//{
//	FASTIO;
//	memset(Dp, -1, sizeof(Dp));
//	cin >> T >> K;
//	for (int i = 0; i < K; ++i)
//		cin >> Cost[i].first >> Cost[i].second;
//
//	cout << Solve(0, 0, 0);
//	return 0;
//}

