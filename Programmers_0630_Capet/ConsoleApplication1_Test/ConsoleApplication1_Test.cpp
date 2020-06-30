#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow)
{
	vector<int> Answer;

	int Calc = brown - 4;
	for (int i = 1; i < yellow + 1; ++i)
	{
		int height = i;
		int width = yellow / i;

		if (yellow % width != 0 || yellow % height != 0) continue;
		if (height > width) break;

		int Result = (width * 2) + (height * 2);
		if (Result == Calc)
		{
			Answer.push_back(width + 2);
			Answer.push_back(height + 2);
			break;
		}
	}

	return Answer;
}

int main()
{

	return 0;
}

