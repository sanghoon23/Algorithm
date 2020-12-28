#include "pch.h"
#include <iostream>
using namespace std;
int M = 0, K = 0, Total = 0, Board[51];
double Solve(int Num, int Cnt)
{
	double T = Total, N = Num, Ret = 1.0;
	while (Cnt--)
	{
		Ret *= N / T;
		--N;
		--T;
	}
	return Ret;
}
int main()
{
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> Board[i];
		Total += Board[i];
	}

	cin >> K;
	double Answer = 0.0;
	for (int i = 0; i < M; ++i)
	{
		if (Board[i] < K) continue;
		Answer += Solve(Board[i], K);
	}
	cout.precision(9);
	cout << Answer;
	return 0;
}

