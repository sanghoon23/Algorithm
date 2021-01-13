#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
#define MMAX 10000
int N = 0, M = 0;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	vector<vector<int>> Board(N + 1, vector<int>(N + 1, MMAX));
	for (int i = 0; i < M; ++i)
	{
		int F, S;
		cin >> F >> S;
		Board[F][S] = 1;
	}
	
	for (int k = 1; k <= N; ++k)
		for (int j = 1; j <= N; ++j)
			for (int i = 1; i <= N; ++i)
				if (Board[j][i] > Board[j][k] + Board[k][i]) Board[j][i] = Board[j][k] + Board[k][i];

	int Answer = 0;
	for (int j = 1; j <= N; ++j)
	{
		int Sum = 1;
		for (int i = 1; i <= N; ++i)
		{
			if (i == j) continue;

			if ((Board[j][i] >= 1 && Board[j][i] < MMAX) || (Board[i][j] >= 1 && Board[i][j] < MMAX)) continue;
			else { Sum = 0; break; }
		}
		Answer += Sum;
	}
	cout << Answer;
	return 0;
}

