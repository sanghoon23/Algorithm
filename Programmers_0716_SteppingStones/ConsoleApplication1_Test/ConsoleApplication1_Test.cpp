#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n)
{
	sort(rocks.begin(), rocks.end());

	vector<int> Calc;
	Calc.push_back(rocks[0]);
	for (int j = 0; j < rocks.size(); ++j)
	{
		int Temp = 0;
		if (j == rocks.size() - 1) Temp = distance - rocks[j];
		else Temp = rocks[j + 1] - rocks[j];

		Calc.push_back(Temp);
	}

	int Answer = distance;
	int Start = 1;
	int End = distance;
	int Mid = 0;
	int Count = 0;
	while (Start <= End)
	{
		Mid = (Start + End) / 2;

		Count = 0;
		int Temp = 0;
		for (int i = 0; i < Calc.size(); ++i)
		{
			if (Calc[i] + Temp < Mid)
			{
				++Count;
				Temp += Calc[i];
			}
			else Temp = 0;
		}

		if (Count > n) End = Mid - 1;
		else if (Count <= n)
		{
			Start = Mid + 1;
			Answer = Mid;
		}
	}

	return Answer;
}

int main()
{
	int Dist = 25;
	
	vector<int> Rocks;
	Rocks.push_back(2);
	Rocks.push_back(14);
	Rocks.push_back(11);
	Rocks.push_back(21);
	Rocks.push_back(17);

	int N = 2;

	int Result = solution(Dist, Rocks, N);


	return 0;
}

