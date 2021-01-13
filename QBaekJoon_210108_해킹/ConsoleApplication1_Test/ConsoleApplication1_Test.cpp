#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define MMAX 10000001
#define PII pair<int, int>
int T = 0, N = 0, D = 0, C = 0;

void Solve(vector<vector<PII>>& Board, int Start)
{
	vector<int> Dist(N + 1, MMAX);
	Dist[Start] = 0;

	priority_queue<PII> Que;
	Que.push({ 0, Start });
	while (!Que.empty())
	{
		int Cost = -(Que.top().first), Idx = Que.top().second;
		Que.pop();

		for (int k = 0; k < Board[Idx].size(); ++k)
		{
			int Next = Board[Idx][k].first, NC = Cost + Board[Idx][k].second;
			if (Dist[Next] > NC)
			{
				Dist[Next] = NC;
				Que.push({ -(NC), Next });
			}
		}
	}

	int Count = 0, TimeMax = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (Dist[i] < MMAX)
		{
			++Count;
			TimeMax = max(TimeMax, Dist[i]);
		}
	}
	printf("%d %d\n", Count, TimeMax);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> D >> C;
		vector<vector<PII>> Board(N + 1, vector<PII>());
		for (int i = 0; i < D; ++i)
		{
			int F, S, W;
			cin >> F >> S >> W;
			Board[S].push_back({ F, W });
		}
		Solve(Board, C);
	}
	return 0;
}

