#include "pch.h"
#include <iostream>
using namespace std;
int N = 0, Input = 0, Board[101][101];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int j = 1; j <= N; ++j)
		for (int i = 1; i <= N; ++i)
			cin >> Board[j][i];

	for (int k = 1; k <= N; ++k)
		for (int j = 1; j <= N; ++j)
			for (int i = 1; i <= N; ++i)
				if (Board[j][k] == 1 && Board[k][i] == 1) Board[j][i] = 1;

	for (int j = 1; j <= N; ++j)
	{
		for (int i = 1; i <= N; ++i)
			printf("%d ", Board[j][i]);
		printf("\n");
	}
	return 0;
}

