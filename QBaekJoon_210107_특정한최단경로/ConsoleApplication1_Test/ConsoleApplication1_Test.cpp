#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define MMAX 800001
#define PII pair<int, int>
int N = 0, E = 0, A = 0, B = 0;
vector<int> Dijkstra(vector<vector<PII>>& Board, int Start)
{
	vector<int> Dist(N + 1, MMAX);
	Dist[Start] = 0; //@ 0 으로 갱신 잊지말자.

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
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> N >> E;
	vector<vector<PII>> Board(N + 1, vector<PII>());
	for (int i = 0; i < E; ++i)
	{
		int F, S, W;
		cin >> F >> S >> W;
		Board[F].push_back({ S, W });
		Board[S].push_back({ F, W });
	}
	cin >> A >> B;

	int Answer = 0;
	vector<int> Root = Dijkstra(Board, 1);
	vector<int> ANode = Dijkstra(Board, A);
	vector<int> BNode = Dijkstra(Board, B);
	Answer = min((Root[A] + ANode[B] + BNode[N]), (Root[B] + BNode[A] + ANode[N]));
	if (Answer >= MMAX) cout << -1 << '\n';
	else cout << Answer << '\n';
	return 0;
}

