#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, L = 0;
int Answer = 0;
int main()
{
	cin >> N >> L;
	vector<int> Pos(N);
	for (int i = 0; i < N; ++i)
		cin >> Pos[i];

	sort(Pos.begin(), Pos.end());

	vector<int> Calc;
	for (int i = 1; i < Pos.size(); ++i)
		Calc.push_back(Pos[i] - Pos[i - 1]);

	int Sum = 0;
	for (int i = 0; i < Calc.size(); ++i)
	{
		Sum += Calc[i];
		if (Sum < L) continue;
		else
		{
			Sum = 0;
			++Answer;
		}
	}
	++Answer;

	if (Pos.size() == 1) cout << 1;
	else cout << Answer;
	return 0;
}

