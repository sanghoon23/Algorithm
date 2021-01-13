#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define MMAX 3000001
#define PII pair<int, int>
int TC = 0, N = 0, M = 0, T = 0;
vector<int> Dijkstra(vector<vector<PII>>& Board, int Start)
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
	return Dist;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> TC;
	while (TC--)
	{
		cin >> N >> M >> T;

		int S, G, H;
		cin >> S >> G >> H;

		vector<vector<PII>> Board(N + 1, vector<PII>());
		for (int i = 0; i < M; ++i)
		{
			int F, S, W;
			cin >> F >> S >> W;
			Board[F].push_back({ S, W });
			Board[S].push_back({ F, W });
		}

		vector<int> RS = Dijkstra(Board, S);
		vector<int> RG = Dijkstra(Board, G);
		vector<int> RH = Dijkstra(Board, H);

		vector<int> Answer;
		for (int i = 0; i < T; ++i)
		{
			int Finish;
			cin >> Finish;
			int ResultA = RS[G] + RG[H] + RH[Finish];
			int ResultB = RS[H] + RH[G] + RG[Finish];
			if(ResultA == RS[Finish] || ResultB == RS[Finish])
				Answer.push_back(Finish);
		}

		sort(Answer.begin(), Answer.end());
		for (int i = 0; i < Answer.size(); ++i)
			printf("%d ", Answer[i]);

		printf("\n");
	}
	return 0;
}

