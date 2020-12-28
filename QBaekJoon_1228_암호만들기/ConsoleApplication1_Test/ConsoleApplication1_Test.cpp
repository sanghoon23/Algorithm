#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int L = 0, C = 0;
char Input, Board[16], P[16], MoumVal[5] = { 'a', 'e', 'i', 'o', 'u' };
void Solve(int Idx, int Count, int Moum)
{
	if (Count == L && Moum >= 1 && Count - Moum >= 2)
	{
		for (int k = 0; k < L; ++k)
			cout << P[k];
		cout << '\n';
		return;
	}

	for (int j = Idx; j < C; ++j)
	{
		P[Count] = Board[j];
		bool bFind = false;
		for (int i = 0; i < 5; ++i)
			if (MoumVal[i] == Board[j]) { bFind = true; break; }

		if(bFind) Solve(j + 1, Count + 1, Moum + 1);
		else Solve(j + 1, Count + 1, Moum);
	}
}

int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; ++i)
	{
		cin >> Input;
		Board[i] = Input;
	}
	sort(Board, Board + C);
	Solve(0, 0, 0);
	return 0;
}

