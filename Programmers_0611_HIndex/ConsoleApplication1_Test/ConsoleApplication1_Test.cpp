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

int solution(vector<int> citations)
{
	sort(citations.begin(), citations.end(), Compare);

	int Max = 0;
	int Count = 0;
	for (int i = 10000; i >= 0; --i)
	{
		if (i > citations.size()) continue;
		Max = i;
		Count = 0;
		for (int j = 0; j < citations.size(); ++j)
		{
			if (citations[j] >= Max) ++Count;
			else break;
		}

		if (Count >= Max) break;
	}

	return Max;
}

int main()
{

	return 0;
}

