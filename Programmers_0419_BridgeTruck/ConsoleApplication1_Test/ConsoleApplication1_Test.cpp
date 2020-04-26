#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

static int Result = 0;

bool Timer(vector<int>& Vec, int Weight, int Insert)
{
	int Front = Vec[0];
	int End = Vec.size() - 1;

	//@Swap
	int CurrentTotal = 0;
	for (int i = 0; i < Vec.size(); ++i)
	{
		if (i == 0) continue;
		Vec[i - 1] = Vec[i];
		if(Vec[i] != -1 ) CurrentTotal += Vec[i];
	}

	++Result;

	if (CurrentTotal + Insert <= Weight)
	{
		Vec[End] = Insert;
		return true;
	}
	else
	{
		Vec[End] = -1;
		return false;
	}
}

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int TotalValue = 0;
	vector<int> Linear(bridge_length, -1);
	int Index = 0;
	while (1)
	{
		if (Index == truck_weights.size())
		{
			Result += bridge_length;
			break;
		}

		bool bRet = Timer(Linear, weight, truck_weights[Index]);
		if (bRet == true)
		{
			++Index;
		}
	}

	return Result;
}

int main()
{
	int Length = 2;
	int Bridge_Weight = 10;

	vector<int> Insert;
	Insert.push_back(7);
	Insert.push_back(4);
	Insert.push_back(5);
	Insert.push_back(6);

	//Insert.push_back(1);
	//Insert.push_back(1);
	//Insert.push_back(1);
	//Insert.push_back(1);
	//Insert.push_back(1);
	//Insert.push_back(2);
	//Insert.push_back(2);

	int Result = solution(Length, Bridge_Weight, Insert);

	return 0;
}

