#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
#define MOD 1000000000
int N = 0, K = 0;
long long Dp[202][202] = { 0, };

int main()
{
	cin >> N >> K;
	memset(Dp, 0, sizeof(Dp));

	for (int j = 0; j <= N; ++j)
		Dp[1][j] = 1;

	for (int j = 2; j <= K; ++j)
	{
		for (int i = 0; i <= N; ++i)
		{
			for (int k = 0; k <= i; ++k)
			{
				Dp[j][i] += Dp[j - 1][k];
			}
			Dp[j][i] %= MOD;
		}
	}
	cout << Dp[K][N];
	return 0;
}

//using namespace std;
//#define MOD 1000000000
//int N = 0, K = 0, Answer = 0;
//int Dp[40001][201] = { 0, };
//
//int Solve(int Sum, int Count)
//{
//	if (Count >= K)
//	{
//		if (Sum == N) return 1;
//		else return 0;
//	}
//
//	int& Ret = Dp[Sum][Count];
//	if (Dp[Sum][Count] != -1) Dp[Sum][Count];
//
//	for (int i = 0; i <= N; ++i)
//		Dp[Sum + i][Count + 1] += Solve(Sum + i, Count + 1);
//}
//
//int main()
//{
//	cin >> N >> K;
//	memset(Dp, 0, sizeof(Dp));
//	Solve(0, 0);
//	cout << Answer;
//	return 0;
//}

