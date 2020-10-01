#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int n)
{
	int Answer = 1;

	int Temp = n - 1;
	for (int i = Temp; i >= 1; --i)
	{
		int Value = i, Count = i;
		while (Count > 0)
		{
			--Count;
			Value += Count;
			if (Value == n)
			{
				++Answer;
				break;
			}
			else if (Value > n)
				break;
		}
	}

	return Answer;
}

int main()
{
	int N = 15;
	int Result = solution(15);

	return 0;
}

