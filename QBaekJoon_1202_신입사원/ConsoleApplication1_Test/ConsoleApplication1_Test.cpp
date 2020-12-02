#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
using namespace std;

int N = 0, Size = 0, F = 0, S = 0;
int main()
{
	cin >> N;
	vector<int> Answer(N, 0);
	vector<vector<pii>> T1(N);
	for (int j = 0; j < N; ++j)
	{
		cin >> Size;
		for (int i = 0; i < Size; ++i)
		{
			cin >> F >> S;
			T1[j].push_back({ F, S });
		}

		sort(T1[j].begin(), T1[j].end());
		int Count = T1[j].size(), S = T1[j][0].second;
		for (int i = 1; i < T1[j].size(); ++i)
		{
			if (T1[j][i].second > S) { --Count; continue; }
			S = T1[j][i].second;
		}
		Answer[j] = Count;

	}

	for (int k = 0; k < N; ++k)
		cout << Answer[k] << endl;
	return 0;
}
