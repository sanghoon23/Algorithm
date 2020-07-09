#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M)
{
	long long Total = 0;
	int Size = budgets.size();
	int Upper = M / Size;

	int Max = 0;
	for (int i = 0; i < Size; ++i)
	{
		if (Max < budgets[i])
		{
			Max = budgets[i];
		}
		Total += budgets[i];
	}
	if (Total <= M) return Max;

	sort(budgets.begin(), budgets.end());

	Total = 0;
	int Index = 0;
	while (1)
	{
		for (int i = Index; i < Size; ++i)
		{
			if (budgets[i] <= Upper)
			{
				Total += (budgets[i]);
			}
			else
			{
				Index = i;
				Total += Upper * (Size - i);
				break;
			}
		}//for

		if (Total > M) break;
		else
		{
			Total -= Upper * (Size - Index);
			++Upper;
		}
	}

	return Upper - 1;
}

int main()
{

	return 0;
}

