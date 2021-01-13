#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N = 0, M = 0;
int main()
{
	cin >> N >> M;
	vector<vector<int>> Board(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; ++i)
	{
		int F, S;
		cin >> F >> S;
		Board[F][S] = 1; Board[S][F] = 1;
	}

	for (int k = 1; k <= N; ++k)
		for (int j = 1; j <= N; ++j)
			for (int i = 1; i <= N; ++i)
			{
				if (Board[j][k] == 0 || Board[k][i] == 0 || j == i) continue;
				if (Board[j][i] == 0) Board[j][i] = Board[j][k] + Board[k][i];
				else Board[j][i] = min(Board[j][i], Board[j][k] + Board[k][i]);
			}

	int Answer = 1;
	int MMIN = 10001;
	for (int j = 1; j <= N; ++j)
	{
		int KalBin = 0;
		for (int i = 1; i <= N; ++i)
			if (i != j) KalBin += Board[j][i];

		if (MMIN > KalBin)
		{
			MMIN = KalBin;
			Answer = j;
		}
	}
	cout << Answer;
	return 0;
}

