#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int N = 0, Board[65][65];
string Input;
string Solve(int Y, int X, int NN)
{
	if (NN == 1)
	{
		if (Board[Y][X] == 0) return "0";
		return "1";
	}

	string Ret;
	for (int j = Y; j < NN + Y; ++j)
	{
		for (int i = X; i < NN + X; ++i)
		{
			if (Board[Y][X] != Board[j][i])
			{
				Ret += "(";
				Ret += Solve(Y, X, NN / 2);
				Ret += Solve(Y, (X + NN / 2), NN / 2);
				Ret += Solve((Y + NN / 2), X, NN / 2);
				Ret += Solve((Y + NN / 2), (X + NN / 2), NN / 2);
				Ret += ")";
				return Ret;
			}
		}
	}
	if (Board[Y][X] == 0) return "0";
	return "1";
}
int main()
{
	cin >> N;
	for (int j = 0; j < N; ++j)
	{
		cin >> Input;
		for (int i = 0; i < Input.size(); ++i)
		{
			Board[j][i] = Input[i] - '0';
		}
	}
	cout << Solve(0, 0, N) << '\n';
	return 0;
}

