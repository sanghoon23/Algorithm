#include "pch.h"
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMAX 987654321
int N, M, Board[101][101];
vector<int> Res[101];

int main()
{
	FASTIO;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) fill(Board[i], Board[i] + 101, MMAX);

	for (int i = 0; i < M; ++i)
	{
		int F, S; cin >> F >> S;
		Board[F][S] = 1;
		Board[S][F] = 1;
	}

	for(int k = 1; k <= N; ++k)
		for(int j = 1; j <= N; ++j)
			for (int i = 1; i <= N; ++i)
			{
				if (Board[j][k] < MMAX && Board[k][i] < MMAX && Board[j][i] > Board[j][k] + Board[k][i])
				{
					Board[j][i] = Board[j][k] + Board[k][i];
				}
			}


	vector<bool> Visited(N + 1, false);
	int K = 1;
	for (int j = 1; j <= N; ++j)
	{
		if (Visited[j] == true) continue;
		Res[K].push_back(j);
		Visited[j] = true;
		for (int i = 1; i <= N; ++i)
		{
			if (i == j) continue;
			if (Board[j][i] < MMAX)
			{
				Res[K].push_back(i);
				Visited[i] = true;
			}
		}
		++K;
	}

	int Size = 0;
	vector<int> Calc;
	for (int k = 1; k <= N; ++k)
	{
		if (Res[k].empty()) break;
		++Size;

		if (Res[k].size() == 1) { Calc.push_back(Res[k][0]); continue; }
		pair<int, int> Top = { -1, MMAX };
		for (int j = 0; j < Res[k].size(); ++j)
		{
			int Maxx = 0;
			for (int i = 1; i <= N; ++i)
			{
				if(Board[Res[k][j]][i] < MMAX && Res[k][j] != i) Maxx = max(Maxx, Board[Res[k][j]][i]);
			}
			if (Top.second > Maxx && Maxx > 0) Top = { Res[k][j], Maxx };
		}
		Calc.push_back(Top.first);
	}

	cout << Size << '\n';
	sort(Calc.begin(), Calc.end());
	for (int i = 0; i < Calc.size(); ++i) cout << Calc[i] << '\n';

	return 0;
}

