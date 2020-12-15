#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
int Time = 0, W = 0;
int Dp[1001][30][3] = { 0, };
int Input[1001] = { 0, };
int Solve(int T, int P, int J)
{
	if (T > Time || J > W) return 0;

	if (Dp[T][J][P] != -1) return Dp[T][J][P];
	Dp[T][J][P] = 0;
	if (P == Input[T]) Dp[T][J][P] = 1;

	if (P == 1)
	{
		Dp[T][J][P] = max(Solve(T + 1, 1, J) + Dp[T][J][P], Solve(T + 1, 2, J + 1) + Dp[T][J][P]);
	}
	else if (P == 2)
	{
		Dp[T][J][P] = max(Solve(T + 1, 2, J) + Dp[T][J][P], Solve(T + 1, 1, J + 1) + Dp[T][J][P]);
	}
	return Dp[T][J][P];
}
int main()
{
	cin >> Time >> W;
	memset(Dp, -1, sizeof(Dp));
	Input[0] = -1;
	for (int i = 1; i <= Time; ++i)
		cin >> Input[i];

	cout << Solve(0, 1, 0);
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//using namespace std;
//int T = 0, W = 0;
//int Dp[1001][30][3] = { 0, };
//int Input[1001] = { 0, };
//int Solve(int Time, int Pos, int PingPong)
//{
//	if (Time >= T || PingPong > W) return 0;
//
//	if (Dp[Time][PingPong][Pos] != -1) return Dp[Time][PingPong][Pos];
//	Dp[Time][PingPong][Pos] = 0;
//	if (Pos == Input[Time]) Dp[Time][PingPong][Pos] = 1;
//
//	if (Pos == 1)
//	{
//		Dp[Time][PingPong][Pos] = max(Solve(Time + 1, 1, PingPong) + Dp[Time][PingPong][Pos], Solve(Time + 1, 2, PingPong + 1) + Dp[Time][PingPong][Pos]);
//	}
//	else if (Pos == 2)
//	{
//		Dp[Time][PingPong][Pos] = max(Solve(Time + 1, 2, PingPong) + Dp[Time][PingPong][Pos], Solve(Time + 1, 1, PingPong + 1) + Dp[Time][PingPong][Pos]);
//	}
//	return Dp[Time][PingPong][Pos];
//}
//int main()
//{
//	cin >> T >> W;
//	memset(Dp, -1, sizeof(Dp));
//	for (int i = 0; i < T; ++i)
//		cin >> Input[i];
//	int Answer = 0;
//	Answer = Solve(0, 1, 0);
//	memset(Dp, -1, sizeof(Dp));
//	Answer = max(Answer, Solve(0, 2, 1));
//	cout << Answer;
//	return 0;
//}

