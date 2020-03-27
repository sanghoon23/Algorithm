#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int FindValue(vector<int>& vec, int Index, int CompareValue)
{
	int RetNum = 0;
	if (Index == 0) //@Index 예외처리.
	{
		return RetNum;
	}

	for (int i = Index - 1; i >= 0; --i) //@Index - 1 부터
	{
		if (vec[i] > CompareValue)
		{
			RetNum = i + 1;
			break;
		}
	}

	return RetNum;
}

vector<int> solution(vector<int> heights)
{
	int size = (int)heights.size();

	vector<int> answer(size);
	for (int i = 0; i < size; ++i)
	{
		answer[i] = FindValue(heights, i, heights[i]);
	}

	return answer;
}

int main()
{

	return 0;
}

