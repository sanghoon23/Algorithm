#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int V = 0;
int main()
{
	cin >> N;
	cin >> V;
	vector<int> Temp(N);
	for (int i = 0; i < N; ++i)
		cin >> Temp[i];

	int Answer = 0;
	for (int i = Temp.size() - 1; i >= 0; --i)
	{
		if (Temp[i] > V) continue;
		int R = (V / Temp[i]);
		Answer += R;
		V -= (Temp[i] * R);
	}

	cout << Answer;
	return 0;
}

