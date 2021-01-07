#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////
//@간선의 역 생각해보기.

#define MMAX 2e9
#define PII pair<int, int>
int N = 0, M = 0, X = 0;
vector<int> Dijkstra(vector<vector<PII>>& Board, int Start)
{
	vector<int> Ret(N + 1, MMAX);

	priority_queue<PII> Que;
	Que.push({ 0, Start });
	while (!Que.empty())
	{
		int Cost = -(Que.top().first), Idx = Que.top().second;
		Que.pop();
		for (int k = 0; k < Board[Idx].size(); ++k)
		{
			int Next = Board[Idx][k].first, NC = Cost + Board[Idx][k].second;
			if (Ret[Next] > NC)
			{
				Ret[Next] = NC;
				Que.push({ -(NC), Next });
			}
		}
	}
	return Ret;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M >> X;
	vector<vector<PII>> Board(N + 1, vector<PII>());
	vector<vector<PII>> RevBoard(N + 1, vector<PII>());
	for (int i = 0; i < M; ++i)
	{
		int F, S, W;
		cin >> F >> S >> W;
		Board[F].push_back({ S, W });
		RevBoard[S].push_back({ F, W });
	}

	int Answer = 0;
	vector<int> XR = Dijkstra(Board, X);
	vector<int> XXR = Dijkstra(RevBoard, X);
	for (int i = 1; i <= N; ++i)
	{
		if (i == X) continue;
		Answer = max(Answer, XR[i] + XXR[i]);
	}
	cout << Answer << '\n';
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//@다 찾아서 구하기.

//#define MMAX 2e9
//#define PII pair<int, int>
//int N = 0, M = 0, X = 0, DistA[1001], DistB[1001];
//
//vector<int> Dijkstra(vector<vector<PII>>& Board, int Start)
//{
//	vector<int> Ret(N + 1, MMAX);
//
//	priority_queue<PII> Que;
//	Que.push({ 0, Start });
//	while (!Que.empty())
//	{
//		int Cost = -(Que.top().first), Idx = Que.top().second;
//		Que.pop();
//		for (int k = 0; k < Board[Idx].size(); ++k)
//		{
//			int Next = Board[Idx][k].first, NC = Cost + Board[Idx][k].second;
//			if (Ret[Next] > NC)
//			{
//				Ret[Next] = NC;
//				Que.push({ -(NC), Next });
//			}
//		}
//	}
//	return Ret;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> N >> M >> X;
//	vector<vector<PII>> Board(N + 1, vector<PII>());
//	for (int i = 0; i < M; ++i)
//	{
//		int F, S, W;
//		cin >> F >> S >> W;
//		Board[F].push_back({ S, W });
//	}
//
//	int Answer = 0;
//	vector<int> XR = Dijkstra(Board, X);
//	for (int i = 1; i <= N; ++i)
//	{
//		if (i == X) continue;
//		vector<int> R = Dijkstra(Board, i);
//		DistA[i] = R[X];
//
//		DistB[i] = XR[i];
//		Answer = max(Answer, DistA[i] + DistB[i]);
//	}
//	cout << Answer << '\n';
//	return 0;
//}

