#include "pch.h"
#include <iostream>
#define PII pair<int, int>
using namespace std;
int N = 0, Board[129][129];
PII SumPair(PII A, PII B)
{
	return { A.first + B.first, A.second + B.second };
}
PII Solve(int Y, int X, int NN)
{
	if (NN == 1)
	{
		if (Board[Y][X] == 0) return { 1, 0 };
		return { 0, 1 };	
	}
	PII Ret = { 0, 0 };
	for (int j = Y; j < NN + Y; ++j) //@여기 부분에서 실수가 있었다. j = 0 으로 해놨었고,
	{
		for (int i = X; i < NN + X; ++i)
		{
			if (Board[j][i] != Board[Y][X])
			{
				Ret = SumPair(Ret, Solve(Y, X, NN / 2));
				Ret = SumPair(Ret, Solve(Y, (X + NN / 2), NN / 2)); //@여기서도 그냥 NN / 2 값을 넘겨주는 실수.
				Ret = SumPair(Ret, Solve((Y + NN / 2), X, NN / 2));
				Ret = SumPair(Ret, Solve((Y + NN / 2), (X + NN / 2), NN / 2));
				return Ret;
			}
		}
	}

	if (Board[Y][X] == 0) return { 1, 0 };
	return { 0, 1 };
}
int main()
{
	cin >> N;
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < N; ++i)
			cin >> Board[j][i];
	PII Result = Solve(0, 0, N);
	cout << Result.first << '\n'; //@하얀색 - 0
	cout << Result.second << '\n'; //@파란색 - 1
	return 0;
}

