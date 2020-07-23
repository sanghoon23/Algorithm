#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<int> Answer;

	for (int i = 0; i < prices.size(); ++i)
	{
		for (int j = i + 1; j < prices.size(); ++j)
		{
			if (prices[i] > prices[j])
			{
				Answer.push_back(j - i);
				break;
			}

			if (j == prices.size() - 1) Answer.push_back(j - i);
		}
	}

	Answer.push_back(0);
	return Answer;
}

int main()
{

	return 0;
}

