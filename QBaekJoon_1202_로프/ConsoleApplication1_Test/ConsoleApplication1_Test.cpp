#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
bool Compare(int a, int b)
{
	return a > b;
}

int main()
{
	cin >> N;
	vector<int> Temp(N);
	for (int i = 0; i < N; ++i)
		cin >> Temp[i];
	sort(Temp.begin(), Temp.end(), Compare);

	int Answer = 0;
	for (int k = 0; k < N; ++k)
		Answer = max((Temp[k] * (k + 1)), Answer);
	cout << Answer;
	return 0;
}
