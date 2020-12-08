#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//@DP
int N = 0;
int House[20][20] = { 0, };
int Dp[20][20][3] = { 0, }; //오른, 아래, 대각

int DP(int N)
{
	Dp[1][2][0] = 1;
	for (int j = 1; j <= N; ++j)
	{
		for (int i = 2; i <= N; ++i)
		{
			if (House[j][i]) continue;

			Dp[j][i][0] += Dp[j][i - 1][0] + Dp[j][i - 1][2];
			Dp[j][i][1] += Dp[j - 1][i][1] + Dp[j - 1][i][2];
			
			if (House[j - 1][i] != 1 && House[j][i - 1] != 1)
				Dp[j][i][2] += Dp[j - 1][i - 1][2] + Dp[j - 1][i - 1][0] + Dp[j - 1][i - 1][1];
		}
	}

	return Dp[N][N][0] + Dp[N][N][1] + Dp[N][N][2];
}

int main()
{
	cin >> N;
	for (int j = 1; j <= N; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			cin >> House[j][i];
		}
	}
	cout << DP(N);
	return 0;
}


//@DFS
//int N = 0, Answer = 0;
//int House[17][17] = { 0, };
//pair<int, int> Dir[3] = { {0, 1}, {1, 0}, {1, 1} }; //오른, 아래, 대각
//
//void DFS(int Y, int X, int D)
//{
//	if (Y == N - 1 && X == N - 1) { ++Answer; return; }
//
//	for (int i = 0; i < 3; ++i)
//	{
//		int YY = Y + Dir[i].first, XX = X + Dir[i].second;
//		if (YY >= N || XX >= N) continue;
//		if (House[YY][XX] == 1) continue;
//		if (D + i == 1) continue;
//
//		if (i == 2) //대각
//		{
//			if (House[YY - 1][XX]) continue;
//			if (House[YY][XX - 1]) continue;
//		}
//		DFS(YY, XX, i);
//	}
//}
//
//int main()
//{
//	cin >> N;
//	for (int j = 0; j < N; ++j)
//	{
//		for (int i = 0; i < N; ++i)
//		{
//			cin >> House[j][i];
//		}
//	}
//	DFS(0, 1, 0);
//	cout << Answer;
//	return 0;
//}

