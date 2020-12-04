#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N = 0, Answer = 0;
int main()
{
	cin >> N;
	vector<int> Temp(N);
	for (int i = 0; i < N; ++i)
		cin >> Temp[i];

	sort(Temp.begin(), Temp.end());

	if (Temp[0] > 1) Answer = 1;
	else if (Temp.size() == 1) Answer = Temp[0] + 1;
	else
	{
		int Sum = 0;
		bool bFind = false;
		for (int i = 0; i < Temp.size() - 1; ++i)
		{
			Sum += Temp[i];
			if (Sum + 1 < Temp[i + 1])
			{
				bFind = true;
				Answer = Sum + 1;
				break;
			}
		}

		if (bFind == false)
		{
			Sum += Temp[Temp.size() - 1];
			Answer = Sum + 1;
		}
	}
	cout << Answer;
	return 0;
}

