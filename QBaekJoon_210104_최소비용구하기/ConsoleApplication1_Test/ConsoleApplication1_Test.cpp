#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define PII pair<int, int>
#define MMAX 2e9
int N = 0, M = 0, Start = 0, End = 0;
void Dijkstra(vector<vector<PII>>& Board, vector<int>& Dist, int Start)
{
	Dist[Start] = 0;
	priority_queue<PII> PQ;
	PQ.push({ 0, Start });

	while (!PQ.empty())
	{
		int Cost = -(PQ.top().first), Idx = PQ.top().second;
		PQ.pop();
		if (Dist[Idx] < Cost) continue;

		for (int j = 0; j < Board[Idx].size(); ++j)
		{
			int NextIdx = Board[Idx][j].first, NC = Board[Idx][j].second;
			int R = Cost + NC;
			if (R < Dist[NextIdx])
			{
				Dist[NextIdx] = R;
				PQ.push({ -R, NextIdx });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	vector<vector<PII>> Board(N + 1, vector<PII>());
	for (int k = 0; k < M; ++k)
	{
		int F, S, C;
		cin >> F >> S >> C;
		Board[F].push_back({ S, C });
	}
	cin >> Start >> End;

	vector<int> Dist(1001, MMAX);
	Dijkstra(Board, Dist, Start);
	cout << Dist[End] << '\n';
	return 0;
}

