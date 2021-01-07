#include "pch.h"
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
#define MMAX 2e9
#define PII pair<int, int>
int N = 0, K = 0;
int Solve(vector<int>& Dist, int Start, int End)
{
	priority_queue<PII> PQ;
	PQ.push({ 0, Start });
	while (!PQ.empty())
	{
		int Cost = -(PQ.top().first), Idx = PQ.top().second;
		PQ.pop();

		if (Idx == 0)
		{
			PQ.push({ -(Cost + 1), Idx + 1 });
			continue;
		}
		while (Idx <= End + 1)
		{
			if (Idx > 100000) break;
			if (Dist[Idx] > Cost)
			{
				Dist[Idx] = Cost;
				PQ.push({ -(Cost + 1), Idx - 1 });
				PQ.push({ -(Cost + 1), Idx + 1 });
			}
			Idx *= 2;
		}
	}
	return Dist[End];
}

int main()
{
	cin >> N >> K;
	if (N == K) { cout << 0; exit(0); }
	if (N > K) { cout << N - K; exit(0); }
	vector<int> Dist(100001, MMAX);
	cout << Solve(Dist, N, K);
	return 0;
}

