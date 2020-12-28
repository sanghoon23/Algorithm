#include "pch.h"
#include <iostream>
using namespace std;
int T = 0, K = 0, N = 0, Sum[15][15];
int main()
{
	for (int i = 1; i <= 14; ++i)
		Sum[0][i] = i;

	for (int j = 1; j <= 14; ++j)
		for (int i = 1; i <= 14; ++i)
			(i == 1) ? Sum[j][i] = 1 : Sum[j][i] = Sum[j][i - 1] + Sum[j - 1][i];

	cin >> T;
	while (T--)
	{
		cin >> K >> N;
		cout << Sum[K][N] << '\n';
	}
	return 0;
}

