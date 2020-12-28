#include "pch.h"
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
long long N = 0, Board[7], Total = 0, Max = 0, MinValue[4];
int main()
{
	//memset(MinValue, 0, sizeof(MinValue));
	fill(MinValue, MinValue + 4, 1e10); //@항상 조심하자. memset 쓸 때,
	cin >> N;
	for (int i = 1; i <= 6; ++i)
	{
		cin >> Board[i];
		Total += Board[i];
		Max = max(Max, Board[i]);
	}
	if (N == 1) { cout << Total - Max; exit(0); }

	swap(Board[4], Board[6]);
	for (int i = 1; i <= 6; ++i)
		MinValue[1] = min(MinValue[1], Board[i]);

	for (int j = 1; j <= 6; ++j)
	{
		for (int i = j + 1; i <= 6; ++i)
		{
			if (j + 3 == i) continue;
			MinValue[2] = min(MinValue[2], Board[j] + Board[i]);
			for (int k = i + 1; k <= 6; ++k)
			{
				if (i + 3 == k || j + 3 == k) continue;
				MinValue[3] = min(MinValue[3], Board[j] + Board[i] + Board[k]);
			}
		}
	}

	long long Answer = 0;
	Answer += MinValue[1] * ((N - 2) * (N - 2) * 5 + (N - 2) * 4);
	Answer += MinValue[2] * ((N - 1) * 4 + (N - 2) * 4);
	Answer += MinValue[3] * 4;
	cout << Answer;
	return 0;
}

