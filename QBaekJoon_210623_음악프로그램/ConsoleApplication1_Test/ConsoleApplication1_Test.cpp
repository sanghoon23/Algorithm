#include "pch.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int N, M, InDegree[1001];
vector<int> Board[1001];

int main()
{
	FASTIO;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int W, F, S; cin >> W;
		cin >> F;
		for (int j = 1; j < W; ++j)
		{
			cin >> S;
			Board[F].push_back(S);
			++InDegree[S];
			F = S;
		}
	}

	vector<int> Result;
	queue<int> Que;
	for (int i = 1; i <= N; ++i)
	{
		if (InDegree[i] == 0)
		{
			Que.push(i);
			Result.push_back(i);
		}
	}

	while (!Que.empty())
	{
		int Idx = Que.front(); Que.pop();

		for (int i = 0; i < Board[Idx].size(); ++i)
		{
			if (--InDegree[Board[Idx][i]] == 0)
			{
				Que.push(Board[Idx][i]);
				Result.push_back(Board[Idx][i]);
			}
		}
	}

	if (Result.size() != N) cout << 0 << '\n';
	else for (int i = 0; i < Result.size(); ++i) cout << Result[i] << '\n';

	return 0;
}

