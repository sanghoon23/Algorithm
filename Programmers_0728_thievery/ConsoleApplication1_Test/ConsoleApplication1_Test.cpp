#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(vector<int> money)
{
	vector<int> Temp1(money.size(), 0);
	Temp1[0] = money[0];
	Temp1[1] = money[0];
	for (int i = 2; i < money.size() - 1; ++i)
	{
		Temp1[i] = max(Temp1[i - 2] + money[i], Temp1[i - 1]);
	}

	vector<int> Temp2(money.size(), 0);
	Temp2[0] = 0;
	Temp2[1] = money[1];
	for (int i = 2; i < money.size(); ++i)
	{
		Temp2[i] = max(Temp2[i - 2] + money[i], Temp2[i - 1]);
	}

	return max(Temp1[money.size() - 2], Temp2[money.size() - 1]);
}

int main()
{
	vector<int> In;
	In.push_back(1);
	In.push_back(2);
	In.push_back(3);
	In.push_back(1);

	int Result = solution(In);

	return 0;
}

