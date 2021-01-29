#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define LL long long
LL N, L, R, X, Answer = 0;

void Solve(vector<LL>& Board, int Mini, int Idx, int Sum)
{
	for (int i = Idx + 1; i < N; ++i)
	{
		if (Sum + Board[i] >= L && Sum + Board[i] <= R)
		{
			if (Board[i] - Mini >= X) ++Answer;
		}
		Solve(Board, Mini, i, Sum + Board[i]);
	}
}

int main()
{
	FASTIO;
	cin >> N >> L >> R >> X;
	vector<LL> Board(N);
	for (int i = 0; i < N; ++i)
		cin >> Board[i];

	sort(Board.begin(), Board.end());

	for (int i = 0; i < N; ++i)
		Solve(Board, Board[i], i, Board[i]);

	cout << Answer;
	return 0;
}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@삽질
//int main()
//{
//	FASTIO;
//	cin >> N >> L >> R >> X;
//	vector<LL> Board(N);
//	for (int i = 0; i < N; ++i)
//		cin >> Board[i];
//
//	sort(Board.begin(), Board.end());
//	vector<vector<int>> Nan(N + 1, vector<int>(N + 1));
//	for (int j = 0; j < N; ++j)
//	{
//		for (int i = j + 1; i < N; ++i)
//			if (Board[i] - Board[j] >= X) Nan[j][i] = 1;
//	}
//
//	LL Answer = 0;
//	for (int j = 0; j < N; ++j)
//	{
//		for (int i = j + 1; i < N; ++i)
//		{
//			if (Nan[j][i] == 0) continue;
//			LL Sum = Board[j] + Board[i];
//			if (Sum >= L && Sum <= R) ++Answer;
//			for (int k = j + 1; k < i; ++k)
//			{
//				Sum += Board[k];
//				if (Sum >= L && Sum <= R) ++Answer;
//			}
//		}
//	}
//	cout << Answer;
//	return 0;
//}

