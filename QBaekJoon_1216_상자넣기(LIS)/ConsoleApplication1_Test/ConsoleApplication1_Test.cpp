#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int N = 0;
int main()
{
	cin >> N;
	vector<int> Temp(N);
	for (int i = 0; i < N; ++i)
		cin >> Temp[i];

	vector<int> Answer;
	for (int i = 0; i < N; ++i)
	{
		if (Answer.empty()) { Answer.push_back(Temp[i]); continue; }
		if (Answer[Answer.size() - 1] < Temp[i]) Answer.push_back(Temp[i]);
		else
		{
			int R = lower_bound(Answer.begin(), Answer.end(), Temp[i]) - Answer.begin();
			Answer[R] = Temp[i];
		}
	}
	cout << Answer.size();
	return 0;
}

