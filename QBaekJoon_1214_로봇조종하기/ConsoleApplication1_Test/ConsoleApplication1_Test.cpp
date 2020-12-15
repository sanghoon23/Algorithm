#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
const long long MMIN = -1e10;

int N = 0, M = 0;
int Board[1001][1001] = { 0, };
int Dp[1001][1001][3] = { 0, };
bool Visited[1001][1001] = { false, };
pair<int, int> Dir[3] = { {0, -1}, {0, 1}, {1, 0}, };
int Solve(int D, int Y, int X)
{
	if (Y == N - 1 && X == M - 1) return Board[Y][X];

	int& Ret = Dp[Y][X][D];
	if (Ret != -1) return Dp[Y][X][D];

	Visited[Y][X] = true;
	long long Calc[3];
	for (int i = 0; i < 3; ++i)
	{
		Calc[i] = MMIN;
		int YY = Y + Dir[i].first, XX = X + Dir[i].second;
		if (YY < 0 || YY >= N || XX < 0 || XX >= M) continue;

		if (Visited[YY][XX] == false)
			Calc[i] = Solve(i, YY, XX);
	}

	Visited[Y][X] = false;
	return Ret = Board[Y][X] + max(max(Calc[0], Calc[1]), Calc[2]);
}

int main()
{
	memset(Dp, -1, sizeof(Dp));
	cin >> N >> M;
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < M; ++i)
			cin >> Board[j][i];

	cout << Solve(0, 0, 0);
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//@삽질
//int N = 0, M = 0;
//int Board[1001][1001] = { 0, };
//int Dp[1001][1001] = { 0, };
//bool Visited[1001][1001] = { false, };
//pair<int, int> Dir[3] = { {0, -1}, {0, 1}, {1, 0}, };
//int Solve(int Y, int X)
//{
//	if (Y < 0 || Y >= N || X < 0 || X >= M) return MMIN;
//	if (Visited[Y][X]) return MMIN;
//	if (Y == N - 1 && X == M - 1) return Board[Y][X];
//	if (Dp[Y][X] != MMIN) return Dp[Y][X];
//
//	Dp[Y][X] = Board[Y][X];
//	Visited[Y][X] = true;
//	long long Calc[3];
//	for (int i = 0; i < 3; ++i)
//	{
//		Calc[i] = MMIN;
//		int YY = Y + Dir[i].first, XX = X + Dir[i].second;
//		Calc[i] = Solve(YY, XX);
//	}
//	Dp[Y][X] = Board[Y][X] + max(max(Calc[0], Calc[1]), Calc[2]);
//	return Dp[Y][X];
//}
//
//int main()
//{
//	memset(Dp, MMIN, sizeof(Dp));
//	cin >> N >> M;
//	for (int j = 0; j < N; ++j)
//		for (int i = 0; i < M; ++i)
//			cin >> Board[j][i];
//
//	cout << Solve(0, 0);
//
//	return 0;
//}

