#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N = 0, M = 0, Answer = 0;
int main()
{
	cin >> N >> M;
	if (N == 1)
	{
		Answer = 1;
	}
	else if (N == 2)
	{
		if (M >= 7) Answer = 4;
		else Answer = 1 + ((M - 1) / 2);
	}
	else
	{
		if (M < 4) Answer = M;
		else if (M >= 4 && M <= 6) Answer = 4;
		else if (M > 6) Answer = M - 2;
	}
	cout << Answer;

	return 0;
}

