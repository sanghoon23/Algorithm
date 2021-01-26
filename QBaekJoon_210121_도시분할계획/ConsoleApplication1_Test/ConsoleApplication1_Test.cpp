#include "pch.h"
#include <iostream>
#include <queue>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@프림 알고리즘

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 100005
#define PII pair<int, int>
int N, M;
int main()
{
	FASTIO;
	cin >> N >> M;
	vector<vector<PII>> Board(N + 1, vector<PII>(N + 1));
	for (int i = 1; i <= M; ++i)
	{
		int F, S, W;
		cin >> F >> S >> W;
		Board[F].push_back({ S,W });
		Board[S].push_back({ F,W });
		//Board[F][S] = min(Board[F][S], W);
	}

	int Answer = 0, Count = 0;
	vector<bool> Visited(N + 1, false);
	priority_queue<PII> PQ;
	PQ.push({ 0, N });

	while (!PQ.empty() && Count < N - 2)
	{
		int Cost = -(PQ.top().first), Idx = PQ.top().second;
		PQ.pop();

		if (Visited[Idx] == true) continue;

		Visited[Idx] = true;
		Answer += Cost;
		++Count;
		for (int k = 0; k < Board[Idx].size(); ++k)
		{
			if (Visited[Board[Idx][k].first] == false)
			{
				PQ.push({ -(Board[Idx][k].second), Board[Idx][k].first });
			}
		}
	}
	cout << Answer << '\n';
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@크루스칼 알고리즘

//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define MSIZE 100005
//#define PII pair<int, int>
//int N, M, Parent[MSIZE];
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
//	if (X != Y) Parent[Y] = X;
//}
//
//int main()
//{
//	FASTIO;
//	cin >> N >> M;
//	for (int i = 1; i <= N; ++i)
//		Parent[i] = i;
//
//	priority_queue<pair<int, PII>> PQ;
//	for (int i = 1; i <= M; ++i)
//	{
//		int F, S, W;
//		cin >> F >> S >> W;
//		PQ.push({ -W, { F, S } });
//	}
//
//	int Answer = 0, Count = 0;
//	while (Count < N - 2)
//	{
//		int Cost = -(PQ.top().first), F = PQ.top().second.first, S = PQ.top().second.second;
//		PQ.pop();
//		if (Find(F) != Find(S))
//		{
//			Marge(F, S);
//			Answer += Cost;
//			++Count;
//		}
//	}
//	cout << Answer << '\n';
//	return 0;
//}
