#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int M = 0, N = 0;
int Map[501][501] = { 0, };
int Dp[501][501] = { 0, };
int Find(int Y, int X)
{
	if (Y < 0 || Y >= M || X < 0 || X >= N) return 0;
	if (Y == M - 1 && X == N - 1) return 1;

	int& Ret = Dp[Y][X];
	if (Dp[Y][X] != -1) return Dp[Y][X];

	Ret = 0;
	if(Y - 1 >= 0 && Map[Y - 1][X] < Map[Y][X])
		Ret += Find(Y - 1, X);

	if (X - 1 >= 0 && Map[Y][X - 1] < Map[Y][X])
		Ret += Find(Y, X - 1);

	if (X + 1 < N && Map[Y][X + 1] < Map[Y][X])
		Ret += Find(Y, X + 1);

	if (Y + 1 >= 0 && Map[Y + 1][X] < Map[Y][X])
		Ret += Find(Y + 1, X);

	return Ret;
}
int main()
{
	cin >> M >> N;
	memset(Dp, -1, sizeof(Dp[0][0]) * 501 * 501);
	for (int j = 0; j < M; ++j)
		for (int i = 0; i < N; ++i)
			cin >> Map[j][i];

	cout << Find(0, 0);
	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//@Visited 를 사용한 코드 - Visited 을 사용할 필요가 없다. -> Dp = -1 을 이용.

//int M = 0, N = 0;
//int Map[501][501] = { 0, };
//long long Dp[501][501] = { 0, };
//bool Visited[501][501] = { false, };
//long long Find(int Y, int X)
//{
//	if (Y < 0 || Y >= M || X < 0 || X >= N) return 0;
//	if (Y == M - 1 && X == N - 1) return 1;
//
//	long long& Ret = Dp[Y][X];
//	if (Dp[Y][X] || Visited[Y][X]) return Dp[Y][X];
//
//	if (Y - 1 >= 0 && Map[Y - 1][X] < Map[Y][X])
//		Ret += Find(Y - 1, X);
//
//	if (X - 1 >= 0 && Map[Y][X - 1] < Map[Y][X])
//		Ret += Find(Y, X - 1);
//
//	if (X + 1 < N && Map[Y][X + 1] < Map[Y][X])
//		Ret += Find(Y, X + 1);
//
//	if (Y + 1 >= 0 && Map[Y + 1][X] < Map[Y][X])
//		Ret += Find(Y + 1, X);
//
//	Visited[Y][X] = true;
//	return Ret;
//}
//int main()
//{
//	cin >> M >> N;
//	for (int j = 0; j < M; ++j)
//		for (int i = 0; i < N; ++i)
//			cin >> Map[j][i];
//
//	cout << Find(0, 0);
//	return 0;
//}
