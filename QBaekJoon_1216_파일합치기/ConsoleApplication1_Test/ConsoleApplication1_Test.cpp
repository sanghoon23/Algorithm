#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//@2차
const int MMAX = 1e9;
int T = 0, K = 0, Val[501], Dp[501][501], Sum[501];
int Solve(int Y, int X)
{
	int& Ret = Dp[Y][X];
	if (Ret != -1) return Ret;

	if (Y == X) return Ret = 0;
	if (Y + 1 == X) return Val[Y] + Val[X];

	Ret = MMAX;
	for (int j = Y; j < X; ++j)
		Ret = min(Ret, Solve(Y, j) + Solve(j + 1, X));

	return Ret += Sum[X] - Sum[Y - 1];
}

int main()
{
	cin >> T;
	for (int u = 0; u < T; ++u)
	{
		memset(Val, 0, sizeof(Val));
		memset(Dp, -1, sizeof(Dp));
		memset(Sum, 0, sizeof(Sum));
		cin >> K;
		for (int j = 1; j <= K; ++j)
		{
			cin >> Val[j];
			Sum[j] = Sum[j - 1] + Val[j];
		}
		cout << Solve(1, K) << endl;
	}
	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//@삽질

//const int MMAX = 1e9;
//int T = 0, K = 0, Val[501], Dp[501], Visited[501];
//int Solve(int Idx, int Sum)
//{
//	int& Ret = Dp[Idx];
//	if (Ret != -1) return Ret;
//	Visited[Idx] = true;
//	Ret = MMAX;
//	for (int i = 0; i < K; ++i)
//	{
//		if (Visited[i] == false)
//		{
//			Visited[i] = true;
//			Ret = min(Ret, Sum + Val[i]);
//
//			Visited[i] = false;
//		}
//	}
//	if (Ret == MMAX) Ret = 0;
//	return Ret;
//}
//
//int main()
//{
//	cin >> T;
//	for (int u = 0; u < T; ++u)
//	{
//		memset(Val, 0, sizeof(Val));
//		memset(Dp, -1, sizeof(Dp));
//		memset(Visited, false, sizeof(Visited));
//		cin >> K;
//		for (int j = 0; j < K; ++j)
//			cin >> Val[j];
//
//		int Answer = MMAX;
//		for(int i = 0; i < K; ++i)
//			Answer = min(Answer, Solve(i, Val[i]));
//
//		cout << Answer;
//	}
//	return 0;
//}

