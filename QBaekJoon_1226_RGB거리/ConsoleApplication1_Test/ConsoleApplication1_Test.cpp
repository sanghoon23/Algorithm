#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int N = 0, Board[1001][1001], Dp[1001][3];
int main()
{
	cin >> N;
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < 3; ++i) /* for(int i = 0; i < N; ++i) 로 해서 틀렸다;; */
			cin >> Board[j][i];
	Dp[0][0] = Board[0][0];
	Dp[0][1] = Board[0][1];
	Dp[0][2] = Board[0][2];
	for (int i = 1; i < N; ++i) // 0-빨, 1-초, 2-파
	{
		Dp[i][0] = min(Dp[i - 1][1], Dp[i - 1][2]) + Board[i][0];
		Dp[i][1] = min(Dp[i - 1][0], Dp[i - 1][2]) + Board[i][1];
		Dp[i][2] = min(Dp[i - 1][0], Dp[i - 1][1]) + Board[i][2];
	}
	cout << min(Dp[N - 1][0], min(Dp[N - 1][1], Dp[N - 1][2]));
	return 0;
}

//int main()
//{
//	cin >> N;
//	for (int j = 0; j < N; ++j)
//		for (int i = 0; i < 3; ++i)
//			cin >> Board[j][i];
//
//	for (int i = 1; i <= N; ++i) // 0-빨, 1-초, 2-파
//	{
//		Dp[i][0] = min(Dp[i - 1][1] + Board[i - 1][0], Dp[i - 1][2] + Board[i - 1][0]);
//		Dp[i][1] = min(Dp[i - 1][0] + Board[i - 1][1], Dp[i - 1][2] + Board[i - 1][1]);
//		Dp[i][2] = min(Dp[i - 1][0] + Board[i - 1][2], Dp[i - 1][1] + Board[i - 1][2]);
//	}
//	cout << min(Dp[N][0], min(Dp[N][1], Dp[N][2]));
//	return 0;
//}

