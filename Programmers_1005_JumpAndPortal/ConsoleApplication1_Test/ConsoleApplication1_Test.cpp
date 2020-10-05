#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int N)
{
	int Answer = 0;

	while (N > 0)
	{
		if (N == 1) { ++Answer; break; }
		if (N % 2 == 1) { N -= 1; ++Answer; }

		N /= 2;
	}

	return Answer;
}

int main()
{

	return 0;
}

