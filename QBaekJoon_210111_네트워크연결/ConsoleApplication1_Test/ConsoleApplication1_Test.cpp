#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@프림 알고리즘

#define PII pair<int, int>
int N = 0, M = 0;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	vector<vector<PII>> Board(N + 1, vector<PII>());
	for (int i = 0; i < M; ++i)
	{
		int F, S, W;
		cin >> F >> S >> W;
		Board[F].push_back({ S, W });
		Board[S].push_back({ F, W });
	}

	int Answer = 0;
	vector<bool> Visited(N + 1, false);
	priority_queue<PII> PQ;
	PQ.push({ 0, 1 });
	while (!PQ.empty())
	{
		int Cost = -(PQ.top().first), Idx = PQ.top().second;
		PQ.pop();

		if (Visited[Idx] == false)
		{
			Answer += Cost;
			Visited[Idx] = true;
			for (int k = 0; k < Board[Idx].size(); ++k)
			{
				if (Visited[Board[Idx][k].first] == false)
					PQ.push({ -(Board[Idx][k].second), Board[Idx][k].first });
			}
		}
	}
	cout << Answer;
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@크루스칼 알고리즘

//#define PII pair<int, int>
//int N = 0, M = 0, Parent[1001];
//
//int Find(int X)
//{
//	if (Parent[X] == X) return X;
//	Parent[X] = Find(Parent[X]);
//	return Parent[X];
//}
//
//void Marge(int X, int Y)
//{
//	X = Find(X);
//	Y = Find(Y);
//	if (X == Y) return;
//	Parent[Y] = X;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> N >> M;
//	for (int i = 1; i <= N; ++i)
//		Parent[i] = i;
//
//	priority_queue<pair<int, PII>> PQ;
//	for (int i = 0; i < M; ++i)
//	{
//		int F, S, W;
//		cin >> F >> S >> W;
//		PQ.push({ -(W), {F, S} });
//	}
//
//	int Answer = -(PQ.top().first);
//	Marge(PQ.top().second.first, PQ.top().second.second);
//	PQ.pop();
//	while (!PQ.empty())
//	{
//		int Cost = -(PQ.top().first), F = PQ.top().second.first, S = PQ.top().second.second;
//		PQ.pop();
//		if (Find(F) == Find(S)) continue;
//		Marge(F, S);
//		Answer += Cost;
//	}
//	cout << Answer;
//	return 0;
//}

