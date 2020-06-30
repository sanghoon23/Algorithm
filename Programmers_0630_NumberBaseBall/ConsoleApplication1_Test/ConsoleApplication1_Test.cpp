#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool Check(vector<vector<int>>& Baseball, int In)
{
	int a = (In / 100);
	int b = (In / 10) % 10;
	int c = In % 10;

	if (a == b || b == c || a == c || a == b == c) return false;
	if (a == 0 || b == 0 || c == 0) return false;

	int Calc[3] = { c, b, a };

	for (int s = 0; s < Baseball.size(); ++s)
	{
		int Strike = 0;
		int Ball = 0;

		for (int j = 0; j < 3; ++j) //@Baseball
		{
			int Dou = static_cast<int>(pow(10, j));
			int Value = (Baseball[s][0] / Dou) % 10;
			for (int i = 0; i < 3; ++i) //@Calc
			{
				if (Value == Calc[i] && i == j)
					++Strike;
				else if (Value == Calc[i] && i != j)
					++Ball;
			}
		}

		if (Strike == Baseball[s][1] && Ball == Baseball[s][2])
		{
			continue;
		}
		else return false;
	}

	return true;
}

int solution(vector<vector<int>> baseball)
{
	int Answer = 0;

	for (int i = 123; i < 987; ++i)
	{
		if (Check(baseball, i) == true)
			++Answer;
	}

	return Answer;
}

int main()
{

	return 0;
}

