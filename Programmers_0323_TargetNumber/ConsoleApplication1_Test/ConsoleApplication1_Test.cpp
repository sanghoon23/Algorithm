#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static int RetCount = 0;
static char operat[2] = { '+', '-' };

void Loop(vector<int>* vec, int LukerNum, int Count, int targetNum)
{
	if (Count == vec->size())
	{
		if (LukerNum == targetNum)
		{
			++RetCount;
			return;
		}
		return;
	}

	for (int j = 0; j < 2; ++j)
	{
		if (operat[j] == '+')
		{
			int InsertNum = LukerNum + (*vec)[Count];
			Loop(vec, InsertNum, Count + 1, targetNum);
		}
		else if (operat[j] == '-')
		{
			int InsertNum = LukerNum - (*vec)[Count];
			Loop(vec, InsertNum, Count + 1, targetNum);
		}
	}
}

int solution(vector<int> numbers, int target)
{
	Loop(&numbers, 0, 0, target);

	return RetCount;
}

int main()
{



	return 0;
}

