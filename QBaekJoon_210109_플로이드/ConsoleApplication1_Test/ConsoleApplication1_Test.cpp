#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MMAX 10000001
int N = 0, M = 0;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<int>> Board(N + 1, vector<int>(N + 1, MMAX));
	for (int j = 1; j <= M; ++j)
	{
		int F, S, W;
		cin >> F >> S >> W;
		Board[F][S] = min(Board[F][S], W);
	}

	for (int k = 1; k <= N; ++k)
		for (int j = 1; j <= N; ++j)
			for (int i = 1; i <= N; ++i)
				if (Board[j][i] > Board[j][k] + Board[k][i])
					Board[j][i] = Board[j][k] + Board[k][i];

	for (int j = 1; j <= N; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			if (Board[j][i] >= MMAX || i == j) printf("%d ", 0);
			else printf("%d ", Board[j][i]);
		}
		printf("\n");
	}
	return 0;
}

