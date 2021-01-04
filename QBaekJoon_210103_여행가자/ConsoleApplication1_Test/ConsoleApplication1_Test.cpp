#include "pch.h"
#include <iostream>
using namespace std;
int N = 0, M = 0, Input = 0, Board[1001], Parent[201];
int Find(int X)
{
	if (Parent[X] == X) return X;
	Parent[X] = Find(Parent[X]);
	return Parent[X];
}

void Union(int X, int Y)
{
	X = Find(X);
	Y = Find(Y);
	if (X == Y) return;
	Parent[Y] = X;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		Parent[i] = i;

	for (int j = 1; j <= N; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			cin >> Input;
			if (Input == 1) Union(j, i);
		}
	}
	for (int i = 1; i <= M; ++i)
		cin >> Board[i];

	for (int k = 1; k <= M - 1; ++k)
		if (Find(Board[k]) != Find(Board[k + 1])) { cout << "NO" << '\n'; exit(0); }
	cout << "YES" << '\n';
	return 0;
}

