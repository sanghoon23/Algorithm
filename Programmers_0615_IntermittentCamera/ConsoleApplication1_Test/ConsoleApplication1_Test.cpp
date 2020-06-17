#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct Distance
{
	int Index = 0;
	int Value = 0;
};


bool Compare(Distance A, Distance B)
{
	return A.Value > B.Value;
}

int Min(int* Calc, int* Poped)
{
	int min = Calc[0];
	(min > Calc[1]) ? min = Calc[1] : min;
	(min > Poped[0]) ? min = Poped[0] : min;
	(min > Poped[1]) ? min = Poped[1] : min;

	return min;
}

int Max(int* Calc, int* Poped)
{
	int max = Calc[0];
	(max < Calc[1]) ? max = Calc[1] : max;
	(max < Poped[0]) ? max = Poped[0] : max;
	(max < Poped[1]) ? max = Poped[1] : max;

	return max;
}

int solution(vector<vector<int>> routes)
{
	int Result = 1;
	sort(routes.begin(), routes.end());

	int Calc = routes[0][1];
	for (int i = 0; i < routes.size() - 1; ++i)
	{
		if (routes[i][1] < Calc) Calc = routes[i][1];
		if (routes[i + 1][0] > Calc)
		{
			++Result;
			Calc = routes[i + 1][1];
		}
	}

	return Result;
}

int main()
{
	vector<vector<int>> Input;

	vector<int> In1;
	In1.push_back(-20);
	In1.push_back(15);

	vector<int> In2;
	In2.push_back(-14);
	In2.push_back(-5);

	vector<int> In3;
	In3.push_back(-18);
	In3.push_back(-13);

	vector<int> In4;
	In4.push_back(-5);
	In4.push_back(-3);

	Input.push_back(In1);
	Input.push_back(In2);
	Input.push_back(In3);
	Input.push_back(In4);

	int Result = solution(Input);

	return 0;
}

