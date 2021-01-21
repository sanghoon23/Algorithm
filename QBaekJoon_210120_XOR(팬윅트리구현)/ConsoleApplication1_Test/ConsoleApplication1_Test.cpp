#include "pch.h"
#include <iostream>
using namespace std;
#define INF 987654321

int N, Q, Fen[2][500501];

void Add(int ty, int idx, int val)
{
	while (idx <= N)
	{
		Fen[ty][idx] ^= val;
		idx += (idx & -idx);
	}
}

int Sum(int ty, int idx)
{
	int ret = 0;
	while (idx)
	{
		ret ^= Fen[ty][idx];
		idx &= (idx - 1);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int A = 1;
	int B = 1 ^ 2;
	int C = 3;
	int D = 1 ^ 2 ^ 3 ^ 4;
	int E = 1 ^ 2 ^ 3 ^ 4 ^ 5;
	printf("%d, %d, %d, %d, %d\n", A, B, C, D, E);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int t;
		cin >> t;
		Add(0, i, t);
		Add(1, i, t);
	}

	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int a, l, r, d;
		cin >> a >> l >> r;
		l++; r++;
		if (l > r) swap(l, r);

		if (a == 1)
		{
			r++;
			cin >> d;
			Add(l & 1, l, d);
			Add(r & 1, r, d);
		}
		else
		{
			l--;
			cout << (Sum(r & 1, r) ^ Sum(l & 1, l)) << "\n";
		}
	}

	return 0;
}
