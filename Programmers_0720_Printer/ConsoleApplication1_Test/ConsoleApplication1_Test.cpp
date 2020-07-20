#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
	int Location = location;
	int Calc = 0;

	bool bFind = false;
	while (!priorities.empty() && bFind == false)
	{
		if (priorities.size() == 1) //@Size 가 1일 땐 break 되지 않음
		{
			++Calc;
			break;
		}

		int Value = priorities[0];
		for (int i = 1; i < priorities.size(); ++i)
		{
			if (Value < priorities[i])
			{
				priorities.erase(priorities.begin());
				priorities.push_back(Value);
				--Location;

				if (Location < 0) Location = priorities.size() - 1;

				break;
			}
			else if (Value >= priorities[i] && i == priorities.size() - 1)
			{
				++Calc;

				if (Location == 0)
				{
					bFind = true;
					break;
				}

				priorities.erase(priorities.begin());
				--Location;
			}
		}
	}

	return Calc;
}

int main()
{
	//@Case 1
	//int Location = 0;

	//vector<int> Insert;
	//Insert.push_back(1);
	//Insert.push_back(1);
	//Insert.push_back(9);
	//Insert.push_back(1);
	//Insert.push_back(1);
	//Insert.push_back(1);

	int Location = 0;

	vector<int> Insert;
	Insert.push_back(1);
	Insert.push_back(2);
	Insert.push_back(3);

	int Result = solution(Insert, Location);

	return 0;
}

