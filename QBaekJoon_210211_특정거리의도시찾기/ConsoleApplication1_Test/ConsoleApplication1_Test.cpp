#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 300001
#define MMAX 987654321
#define PII pair<int, int>
int N, M, K, X;
vector<int> Board[MSIZE];

void Solve()
{
	vector<int> Dist(N + 1, MMAX);
	Dist[X] = 0;
	priority_queue<PII> PQ;
	PQ.push({ 0, X });
	while (!PQ.empty())
	{
		int Cost = -(PQ.top().first), Idx = PQ.top().second;
		PQ.pop();
		for (int Next : Board[Idx])
		{
			if (Dist[Next] > Cost + 1)
			{
				Dist[Next] = Cost + 1;
				PQ.push({ -(Cost + 1), Next });
			}
		}
	}
	vector<int> Answer;
	for (int i = 1; i <= N; ++i)
		if (Dist[i] == K) Answer.push_back(i);

	if (Answer.empty()) cout << -1;
	else
	{
		sort(Answer.begin(), Answer.end());
		for (int k = 0; k < Answer.size(); ++k)
			cout << Answer[k] << '\n';
	}
}

int main()
{
	FASTIO;
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; ++i)
	{
		int F, S; cin >> F >> S;
		Board[F].push_back(S);
	}
	Solve();
	return 0;
}

