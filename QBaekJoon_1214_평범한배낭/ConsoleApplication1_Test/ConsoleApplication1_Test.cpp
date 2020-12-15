#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
//int N = 0, K = 0;
//int Weight[101] = { 0, };
//int Value[101] = { 0, };
//
//int Dp[101][100001] = { 0, };
//int Solve(int Index, int TW)
//{
//	if (Index >= N) return 0;
//	int& Ret = Dp[Index][TW];
//	if (Ret != -1) return Dp[Index][TW];
//
//	Ret = Solve(Index + 1, TW);
//
//	if (TW >= Weight[Index])
//	{
//		Ret = max(Ret, Solve(Index + 1, TW - Weight[Index]) + Value[Index]);
//	}
//	return Ret;
//}
//
//int main()
//{
//	memset(Dp, -1, sizeof(Dp));
//	cin >> N >> K;
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> Weight[i];
//		cin >> Value[i];
//	}
//
//	int MVal = 0;
//	for (int i = 1; i <= K; ++i)
//		MVal = max(MVal, Solve(0, i));
//
//	cout << MVal;
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//@참고

int N, K, W[105], V[105], dp[100005];

int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> W[i];
		cin >> V[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = K; j >= W[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
		}
	}

	printf("%d", dp[K]);
}
