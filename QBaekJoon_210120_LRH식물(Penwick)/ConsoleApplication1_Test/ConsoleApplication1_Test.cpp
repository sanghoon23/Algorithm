#include "pch.h"
#include <iostream>
using namespace std;

#define MSIZE 100010
int N, SegTree[MSIZE];
void Update(int Idx, int Val)
{
	while (Idx <= MSIZE - 9)
	{
		SegTree[Idx] += Val;
		Idx += (Idx & (-Idx));
	}
}

int Query(int Idx)
{
	int Ret = 0;
	while (Idx > 0)
	{
		Ret += SegTree[Idx];
		Idx -= (Idx & (-Idx));
	}
	return Ret;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int F, S;
		cin >> F >> S;

		int Left = Query(F);
		int Right = Query(S);

		Update(F, -Left);
		Update(F + 1, Left);
		Update(S, -Right);
		Update(S + 1, Right);

		Update(F + 1, 1);
		Update(S, -1);

		cout << Left + Right << '\n';
	}
	return 0;
}

