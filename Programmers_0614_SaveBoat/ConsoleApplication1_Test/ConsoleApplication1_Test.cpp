#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool Compare(int a, int b)
{
	return a > b;
}

int solution(vector<int> people, int limit)
{
	sort(people.begin(), people.end(), Compare);
	int Count = people.size();
	int j = people.size();
	for (int i = 0; i < people.size(); ++i)
	{
		if (i >= j - 1) break;

		if (people[i] + people[j - 1] <= limit)
		{
			--j;
			--Count;
		}
	}

	return Count;
}

int main()
{
	vector<int> Input;
	Input.push_back(70);
	Input.push_back(50);
	Input.push_back(80);
	Input.push_back(50);

	int Limit = 100;

	int Result = solution(Input, Limit);

	return 0;
}

