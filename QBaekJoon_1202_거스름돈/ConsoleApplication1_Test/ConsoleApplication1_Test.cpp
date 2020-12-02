#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int P[6] = { 500, 100, 50, 10, 5, 1 };
int main()
{
	cin >> N;
	int Answer = 0;
	int Remain = 1000 - N;
	for (int i = 0; i < 6; ++i)
	{
		if (P[i] > Remain) continue;
		int V = Remain / P[i];
		Answer += V;
		Remain -= V * P[i];
	}
	cout << Answer;
	return 0;
}

