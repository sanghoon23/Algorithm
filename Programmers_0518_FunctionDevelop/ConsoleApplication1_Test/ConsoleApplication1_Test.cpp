#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> Result;
	int Index = 0;
	int size = progresses.size();
	while (1)
	{
		int Insert = 0;
		for (int i = Index; i < size; ++i)
		{
			progresses[i] += speeds[i];
			if (progresses[i] >= 100 && Index == i)
			{
				++Insert;
				++Index;
			}
		}

		if (Insert != 0)
		{
			Result.push_back(Insert);
		}

		if (Index >= size)
			break;
	}

	return Result;
}

int main()
{

	return 0;
}

