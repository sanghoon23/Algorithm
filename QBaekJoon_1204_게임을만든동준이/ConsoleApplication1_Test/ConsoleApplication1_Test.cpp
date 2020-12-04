#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> Temp;
int N = 0, MinRange = 0, Answer = 0;
int FindMinIndex()
{
	int Ret = 0, Index = 0;
	bool bFind = false;
	for (int i = 0; i < Temp.size(); ++i)
	{
		if (MinRange >= Temp[i]) continue;

		bFind = true;
		if (Ret == 0) Ret = Temp[i];
		else
		{
			Ret = min(Ret, Temp[i]);
			Index = i;
		}
	}

	MinRange = Temp[Index];
	if (bFind == true) return Index;
	else return -1;
}

int main()
{
	cin >> N;

	Temp.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> Temp[i];

	while (1)
	{
		int MinIndex = FindMinIndex();
		if (MinIndex == -1) break;

		for (int i = MinIndex; i > 0; --i)
		{
			if (Temp[i - 1] >= Temp[i])
			{
				int R = Temp[i - 1] - Temp[i] + 1;
				Temp[i - 1] -= R;
				Answer += R;
			}
		}
	}

	cout << Answer;
	return 0;
}

