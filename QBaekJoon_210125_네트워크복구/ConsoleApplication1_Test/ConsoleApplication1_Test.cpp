#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PII pair<int, int>
#define MSIZE 1001
#define MMAX 10001
int N, M;
vector<PII> Board[MSIZE];

vector<int> Dikjstra(int Start)
{
	vector<int> Ret(N + 1, -1);
	vector<int> Dist(N + 1, MMAX);
	Dist[Start] = 0;
	priority_queue<PII> PQ;
	PQ.push({ 0, Start });
	while (!PQ.empty())
	{
		int Cost = -(PQ.top().first), Idx = PQ.top().second;
		PQ.pop();
		for (PII Next : Board[Idx])
		{
			int NextIdx = Next.first, NC = Cost + Next.second;
			if (Dist[NextIdx] > NC)
			{
				Dist[NextIdx] = NC;
				Ret[NextIdx] = Idx;
				PQ.push({ -NC, NextIdx });
			}
		}
	}
	return Ret;
}

int main()
{
	FASTIO; //@이거 쓰면 printf 쓰지 말자.
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		Board[A].push_back({ B, C });
		Board[B].push_back({ A, C });
	}
	vector<int> Result = Dikjstra(1);
	cout << N - 1 << '\n';
	for (int k = 2; k <= N; ++k)
		cout << Result[k] << " " << k << '\n';

	return 0;
}

