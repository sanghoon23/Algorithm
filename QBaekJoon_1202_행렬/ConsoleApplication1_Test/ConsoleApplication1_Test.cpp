#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Row = 0, Col = 0;
string T = "";
int Answer = 0, NoneAnswer = -1;
vector<vector<int>> A;
vector<vector<int>> B;

bool Check()
{
	for (int j = 0; j < Row; ++j)
	{
		for (int i = 0; i < Col; ++i)
		{
			if (A[j][i] != B[j][i]) return false;
		}
	}
	return true;
}

void Calc(int F, int S)
{
	for (int j = F; j < F + 3; ++j)
	{
		for (int i = S; i < S + 3; ++i)
		{
			if (A[j][i] == 0) A[j][i] = 1;
			else A[j][i] = 0;
		}
	}
}

int main()
{
	cin >> Row >> Col;

	A.resize(Row);
	for (int j = 0; j < Row; ++j)
	{
		cin >> T;
		A.push_back(vector<int>());
		for (int i = 0; i < Col; ++i)
		{
			A[j].push_back(T[i] - 48);
		}
	}

	B.resize(Row);
	for (int j = 0; j < Row; ++j)
	{
		cin >> T;
		B.push_back(vector<int>());
		for (int i = 0; i < Col; ++i)
		{
			B[j].push_back(T[i] - 48);
		}
	}

	pair<int, int> Point = { 0, 0 };
	while (Point.first < Row - 2)
	{
		int F = Point.first, S = Point.second;
		if (Point.second >= Col - 2)
		{
			++(Point.first);
			Point.second = 0;
			continue;
		}

		if (A[F][S] != B[F][S])
		{
			Calc(F, S);
			++Answer;
		}
		++(Point.second);
	}

	if (Check() == false) cout << NoneAnswer;
	else cout << Answer;

	return 0;
}

