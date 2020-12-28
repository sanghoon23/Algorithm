#include "pch.h"
#include <iostream>
using namespace std;
int K = 0, Values[14], P[14];
void Solve(int Idx, int Count)
{
	if (Count == 6)
	{
		for (int i = 0; i < 6; ++i)
			cout << P[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = Idx; i < K; ++i)
	{
		P[Count] = Values[i];
		Solve(i + 1, Count + 1);
	}
}

int main()
{
	while (1)
	{
		cin >> K;
		if (K == 0) break;
		for (int i = 0; i < K; ++i)
			cin >> Values[i];
		Solve(0, 0);
		cout << '\n';
	}
	return 0;
}

