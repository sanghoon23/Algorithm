#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
#define PII pair<int, int>
int N = 0, E = 0;

void Solve(vector<vector<PII>>& Board, int Start, int End)
{
	vector<pair<int, vector<int>>> Dist(N + 1, { 100000000, vector<int>() });
	Dist[Start].first = 0;

	priority_queue<pair<int, vector<int>>> Que;
	vector<int> In;
	In.push_back(Start);
	Que.push({0, In});
	while (!Que.empty())
	{
		int Cost = -(Que.top().first);
		vector<int> Vec = Que.top().second;
		int Idx = Vec[Vec.size() - 1];
		Que.pop();

		for (int k = 0; k < Board[Idx].size(); ++k)
		{
			int Next = Board[Idx][k].first, NC = Cost + Board[Idx][k].second;
			if (Dist[Next].first > NC)
			{
				vector<int> NV = Vec;
				NV.push_back(Next);
				Dist[Next].first = NC;
				Dist[Next].second = NV;
				Que.push({ -(NC), NV });
			}
		}
	}

	cout << Dist[End].first << '\n';
	cout << Dist[End].second.size() << '\n';
	for (int i = 0; i < Dist[End].second.size(); ++i)
		printf("%d ", Dist[End].second[i]);

}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> E;
	vector<vector<PII>> Board(N + 1, vector<PII>());
	for (int i = 0; i < E; ++i)
	{
		int F, S, W;
		cin >> F >> S >> W;
		Board[F].push_back({ S, W });
	}
	int Start, End;
	cin >> Start >> End;
	Solve(Board, Start, End);
	return 0;
}

