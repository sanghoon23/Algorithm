#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;
int T = 0, N = 0;
int main()
{
	cin >> T;
	vector<int> Height;
	deque<int> DQ;
	while (T--)
	{
		Height.clear();
		DQ.clear();
		cin >> N;
		Height.resize(N);
		for (int i = 0; i < N; ++i) { cin >> Height[i]; }
		sort(Height.begin(), Height.end());
		for (int i = Height.size() - 1; i >= 0; --i)
			(i % 2 == 1) ? DQ.push_front(Height[i]) : DQ.push_back(Height[i]);
		
		int Answer = 0, F = 0, S = 0;
		do
		{
			if (Answer == 0)
			{
				F = DQ.front(); DQ.pop_front();
				S = DQ.front(); DQ.pop_front();
			}
			else
			{
				F = S;
				S = DQ.front(); DQ.pop_front();
			}
			Answer = max(Answer, abs(F - S));
		} while (!DQ.empty());
		cout << Answer << endl;
	}
	return 0;
}

