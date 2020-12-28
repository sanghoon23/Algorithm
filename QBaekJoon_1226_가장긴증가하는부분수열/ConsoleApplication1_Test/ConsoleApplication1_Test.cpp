#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N = 0, Input = 0;
int main()
{
	cin >> N;
	vector<int> Temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> Input;
		if (Temp.empty()) Temp.push_back(Input);
		else
		{
			if (Temp[Temp.size() - 1] < Input) Temp.push_back(Input);
			else
			{
				int R = lower_bound(Temp.begin(), Temp.end(), Input) - Temp.begin();
				Temp[R] = Input;
			}
		}
	}
	cout << Temp.size();
	return 0;
}

