#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int N = 0;

int main()
{
	cin >> N;

	int Answer = -1;

	int V = N / 5;
	while (V >= 0)
	{
		int Remain = N - (V * 5);
		if (Remain % 3 == 0)
		{
			Answer = V + (Remain / 3);
			break;
		}
		--V;
	}

	cout << Answer;
	return 0;
}

