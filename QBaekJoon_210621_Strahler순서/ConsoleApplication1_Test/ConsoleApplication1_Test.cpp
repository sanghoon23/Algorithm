#include "pch.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PII pair<int, int>

int T, K, M, P, Cost[1001], InDegree[1001];
PII Calc[1001];
vector<int> Board[1001];

int main()
{
	FASTIO;
	cin >> T;
	while (T--)
	{
		cin >> K >> M >> P;
		memset(Cost, 0, sizeof(Cost));
		memset(InDegree, 0, sizeof(InDegree));
		memset(Calc, 0, sizeof(Calc));

		for (int i = 0; i <= M; ++i) Board[i].clear();

		for (int i = 0; i < P; ++i)
		{
			int F, S; cin >> F >> S;
			Board[F].push_back(S);
			++InDegree[S];
		}

		queue<int> Que;
		for (int i = 1; i <= M; ++i)
		{
			if (InDegree[i] == 0)
			{
				Cost[i] = 1;
				Que.push(i);
			}
		}

		while (!Que.empty())
		{
			int Idx = Que.front(); Que.pop();

			for (int i = 0; i < Board[Idx].size(); ++i)
			{
				int NI = Board[Idx][i];
				if (Calc[NI].first == Cost[Idx]) ++Calc[NI].second;
				else if (Calc[NI].first < Cost[Idx])
				{
					Calc[NI].first = Cost[Idx];
					Calc[NI].second = 1;
				}

				if (--InDegree[NI] == 0)
				{
					if (Calc[NI].second > 1) Cost[NI] = Calc[NI].first + 1;
					else Cost[NI] = Calc[NI].first;

					Que.push(NI);
				}
			}
		}
		cout << K << " " << Cost[M] << '\n';
	}
	return 0;
}

