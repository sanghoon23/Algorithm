#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//#define MMAX 2147483647
//#define MMAX 987654321
#define MMAX 2e9
#define PII pair<int, int>
int V = 0, E = 0, K = 0, Dist[20001];
void Dijkstra(vector<vector<PII>>& Edge, vector<int>& Dist, int Start)
{
	Dist[Start] = 0;

	priority_queue<PII> PQ; //@first - Cost, second - Idx
	PQ.push({ 0, Start });
	while (!PQ.empty())
	{
		PII Poped = PQ.top();
		PQ.pop();
		int Cost = -(Poped.first), Idx = Poped.second;
		if (Dist[Idx] < Cost) continue;

		for (int j = 0; j < Edge[Idx].size(); ++j)
		{
			int Next = Edge[Idx][j].first, NC = Edge[Idx][j].second;
			int R = Cost + NC;
			if (R < Dist[Next])
			{
				Dist[Next] = R;
				PQ.push({ -R, Next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> V >> E >> K;
	vector<int> Dist(20001, MMAX);
	vector<vector<PII>> Edge(V + 1, vector<PII>());
	for (int k = 0; k < E; ++k)
	{
		int F, S, W;
		cin >> F >> S >> W;
		Edge[F].push_back({ S, W });
	}

	Dijkstra(Edge, Dist, K);

	for (int k = 1; k <= V; ++k)
	{
		if (Dist[k] == MMAX) cout << "INF" << '\n';
		else cout << Dist[k] << '\n';
	}
	return 0;
}

