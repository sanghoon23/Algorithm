#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

/*
데이터 처리는 들어가기 전에 해주는게 시간적으로 좋음.
DFS - 기저 사실 및 정답 처리 후, 밑에 들어가기 전 처리
BFS - 큐에서 받고 정답 처리 후, 들어가기전 처리
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////
//@DFS 이용, (시간 오래 걸림)

using namespace std;
#define MMAX 2e9
#define PII pair<int,int>
int N = 0, M = 0, Board[101][101], Dp[101][101];
PII Dir[4] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
void Solve(int Y, int X, int Count)
{
	Dp[Y][X] = Count;
	if (Y == N - 1 && X == M - 1) return;
	for (int k = 0; k < 4; ++k)
	{
		int YY = Y + Dir[k].first, XX = X + Dir[k].second;
		if (YY < 0 || YY >= N || XX < 0 || XX >= M) continue;
		if (Board[YY][XX] == 0 && Dp[YY][XX] > Count)
			Solve(YY, XX, Count);
		else if (Board[YY][XX] == 1 && Dp[YY][XX] > Count + 1)
			Solve(YY, XX, Count + 1);
	}
}
int main()
{
	memset(Dp, -1, sizeof(Dp));
	cin >> M >> N;
	for (int j = 0; j < N; ++j)
	{
		string Input;
		cin >> Input;
		for (int i = 0; i < M; ++i)
		{
			Dp[j][i] = MMAX;
			Board[j][i] = Input[i] - '0';
		}
	}
	Solve(0, 0, 0);
	cout << Dp[N - 1][M - 1] << '\n';
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
//@우선순위 큐를 이용한 다익스트라.

//#define MMAX 2e9
//#define PII pair<int,int>
//int N = 0, M = 0, Board[101][101];
//PII Dir[4] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
//int main()
//{
//	cin >> M >> N;
//	for (int j = 0; j < N; ++j)
//	{
//		string Input;
//		cin >> Input;
//		for (int i = 0; i < M; ++i)
//			Board[j][i] = Input[i] - '0';
//	}
//
//	vector<vector<int>> Dp(101, vector<int>(101, MMAX));
//	priority_queue<pair<int, PII>> Que;
//	Que.push({ 0, { 0, 0 } });
//
//	int Answer = MMAX;
//	while (!Que.empty())
//	{
//		int Y = Que.top().second.first, X = Que.top().second.second;
//		int Cost = -(Que.top().first);
//		Que.pop();
//		
//		if (Y == N - 1 && X == M - 1)
//		{
//			Answer = min(Answer, Cost);
//			continue;
//		}
//
//		//if (Board[Y][X] == 1) ++Cost;
//		//if (Dp[Y][X] <= Cost) continue;
//		//Dp[Y][X] = Cost;
//
//		for (int k = 0; k < 4; ++k)
//		{
//			int YY = Y + Dir[k].first, XX = X + Dir[k].second;
//			if (YY < 0 || YY >= N || XX < 0 || XX >= M) continue;
//
//			int NC = Cost;
//			if (Board[YY][XX] == 1) ++NC;
//			if (Dp[YY][XX] > NC)
//			{
//				Dp[YY][XX] = NC;
//				Que.push({ -(NC), {YY, XX} });
//			}
//		}
//	}
//	cout << Answer;
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////
//@DP 로는 구하기 어려운 이유는??
/*
*210104
음..
일단 방향성에 관한 DP 로 지금 아래와 같이 풀었는데,
*팩트는 방향의 순서에 따라서 값이 변화된다.
이 말은 즉, 어느 부분문제가 우리가 구하고자하는 최종문제까지의 문제까지 이어가지 못한다.

*210105
-참고
https://devuna.tistory.com/32
https://twinparadox.tistory.com/604


라고, 어제 생각했다..
근본적인 문제는 DFS 이다.

*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@DP 를 이용한 DFS - 삽질

//#define MMAX 2e9
//#define PII pair<int,int>
//int N = 0, M = 0, Board[101][101], Dp[101][101][4];
//PII Dir[4] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
//int Solve(int Y, int X, int D)
//{
//	if (Y == N - 1 && X == M - 1) return 0;
//
//	int& Ret = Dp[Y][X][D];
//	if (Ret != -1) return Ret;
//
//	Ret = 0;
//	int MM = MMAX;
//	for (int k = 0; k < 4; ++k)
//	{
//		int YY = Y + Dir[k].first, XX = X + Dir[k].second;
//		if (YY < 0 || YY >= N || XX < 0 || XX >= M) continue;
//
//		if (Board[Y][X] == 0) MM = min(MM, Solve(YY, XX, k));
//		else MM = min(MM, Solve(YY, XX, k) + 1);
//	}
//
//	for (int i = 0; i < 4; ++i)
//	{
//		if (Dp[Y][X][i] != -1)
//		{
//			MM = min(MM, Dp[Y][X][i]);
//		}
//	}
//
//	Ret += MM;
//	return Ret;
//}
//int main()
//{
//	memset(Dp, -1, sizeof(Dp));
//	cin >> M >> N;
//	for (int j = 0; j < N; ++j)
//	{
//		string Input;
//		cin >> Input;
//		for (int i = 0; i < M; ++i)
//			Board[j][i] = Input[i] - '0';
//	}
//
//	cout << Solve(0, 0, 0) << '\n';
//	return 0;
//}

