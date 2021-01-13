#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@프림 알고리즘

#define MMAX 10000001
#define PII pair<int, int>
int V = 0, E = 0;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> V >> E;
	vector<vector<PII>> Board(V + 1, vector<PII>());
	for (int i = 0; i < E; ++i)
	{
		int F, S, W;
		cin >> F >> S >> W;
		Board[F].push_back({ S, W });
		Board[S].push_back({ F, W });
	}

	int Answer = 0;
	vector<bool> Visited(V + 1, false);
	priority_queue<PII> PQ;
	PQ.push({ 0, 1 }); //@first - Cost, second - Idx

	while (!PQ.empty())
	{
		int Cost = -(PQ.top().first), Idx = PQ.top().second;
		PQ.pop();

		if (Visited[Idx] == false)
		{
			Visited[Idx] = true;
			Answer += Cost;
			for (int k = 0; k < Board[Idx].size(); ++k)
			{

				if(Visited[Board[Idx][k].first] == false)
					PQ.push({ -(Board[Idx][k].second), Board[Idx][k].first });
			}
		}
	}
	cout << Answer;
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@크루스칼 알고리즘

//#define PII pair<int, int>
//int V = 0, E = 0, Parent[10001];
//int Find(int X)
//{
//	if (Parent[X] == X) return X;
//	Parent[X] = Find(Parent[X]);
//	return Parent[X];
//}
//
//void Marge(int Y, int X)
//{
//	Y = Find(Y);
//	X = Find(X);
//	if (Y == X) return;
//	Parent[X] = Y;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> V >> E;
//	for (int i = 1; i <= V; ++i)
//		Parent[i] = i;
//
//	priority_queue<pair<int, PII>> PQ;
//	for (int i = 0; i < E; ++i)
//	{
//		int F, S, W;
//		cin >> F >> S >> W;
//		PQ.push({ -(W), {F, S} });
//	}
//
//	int Answer = -(PQ.top().first);
//	Marge(PQ.top().second.first, PQ.top().second.second);
//	PQ.pop();
//
//	while (!PQ.empty())
//	{
//		int Cost = -(PQ.top().first), F = PQ.top().second.first, S = PQ.top().second.second;
//		PQ.pop();
//
//		if (Find(F) != Find(S))
//		{
//			Marge(F, S);
//			Answer += Cost;
//		}
//	}
//	cout << Answer;
//	return 0;
//}

