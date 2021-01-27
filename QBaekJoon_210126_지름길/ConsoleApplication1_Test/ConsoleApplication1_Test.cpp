#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PII pair<int, int>
#define MMAX 100000001
#define MSIZE 10001
int N, D;
vector<PII> Board[MSIZE];

int Solve(int Start)
{
	vector<int> Dist(D + 1, MMAX);
	Dist[Start] = 0;
	priority_queue<PII> PQ;
	PQ.push({ 0, Start });
	while (!PQ.empty())
	{
		int Cost = -(PQ.top().first), Idx = PQ.top().second;
		PQ.pop();
		if (Idx + 1 <= D && Dist[Idx + 1] > Cost + 1)
		{
			Dist[Idx + 1] = Cost + 1;
			PQ.push({ -(Cost + 1), Idx + 1 });
		}
		if (Idx <= D && Board[Idx].size() > 0)
		{
			for (PII Next : Board[Idx])
			{
				int NC = Cost + Next.second, NextIdx = Next.first;
				if (Dist[NextIdx] > NC)
				{
					Dist[NextIdx] = NC;
					PQ.push({ -NC, NextIdx });
				}
			}
		}
	}
	return Dist[D];
}

int main()
{
	FASTIO;
	cin >> N >> D;
	vector<int> Dp(D + 1, MMAX);
	for (int i = 0; i < N; ++i)
	{
		int F, S, W;
		cin >> F >> S >> W;
		if (D < S || (S -F) < W) continue;
		Board[F].push_back({ S, W });
	}
	cout << Solve(0) << '\n';
	return 0;
}

