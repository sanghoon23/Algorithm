#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 101
int N, M, Board[MSIZE][MSIZE], RevBoard[MSIZE][MSIZE];
int main()
{
	FASTIO;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int F, S; cin >> F >> S;
		Board[F][S] = 1;
		RevBoard[S][F] = 1;
	}

	for (int k = 1; k <= N; ++k)
		for (int j = 1; j <= N; ++j)
			for (int i = 1; i <= N; ++i)
				if (Board[j][i] || Board[j][k] && Board[k][i]) Board[j][i] = 1;

	for (int k = 1; k <= N; ++k)
		for (int j = 1; j <= N; ++j)
			for (int i = 1; i <= N; ++i)
				if (RevBoard[j][i] || RevBoard[j][k] && RevBoard[k][i]) RevBoard[j][i] = 1;

	for (int j = 1; j <= N; ++j)
	{
		int Result = 0;
		for (int i = 1; i <= N; ++i)
			if (Board[j][i] == 0 && j != i) ++Result;

		for (int k = 1; k <= N; ++k)
			if (RevBoard[j][k] == 1 && j != k) --Result;

		cout << Result << '\n';
	}
	return 0;
}

