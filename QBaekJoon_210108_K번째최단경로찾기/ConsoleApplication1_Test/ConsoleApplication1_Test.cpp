#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MMAX 1000001
#define PII pair<int, int>
int N = 0, M = 0, K = 0;
priority_queue<int> Find[1001];

void Solve(vector<vector<PII>>& Board, int Start)
{
	Find[Start].push(0);

	priority_queue<PII> Que;
	Que.push({ 0, Start });
	while (!Que.empty())
	{
		int Cost = -(Que.top().first), Idx = Que.top().second;
		Que.pop();

		for (int k = 0; k < Board[Idx].size(); ++k)
		{
			int Next = Board[Idx][k].first, NC = Cost + Board[Idx][k].second;

			if (Find[Next].size() < K)
			{
				Que.push({ -(NC), Next });
				Find[Next].push(NC);
			}
			else
			{
				if (Find[Next].top() > NC)
				{
					Find[Next].pop();
					Find[Next].push(NC);
					Que.push({ -(NC), Next });
				}
			}
		}
	}//(while)
	for (int i = 1; i <= N; ++i)
	{
		if (Find[i].size() < K) cout << -1 << '\n';
		else cout << Find[i].top() << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	vector<vector<PII>> Board(N + 1, vector<PII>());
	for (int i = 0; i < M; ++i)
	{
		int F, S, W;
		cin >> F >> S >> W;
		Board[F].push_back({ S, W });
	}
	Solve(Board, 1);
	return 0;
}

