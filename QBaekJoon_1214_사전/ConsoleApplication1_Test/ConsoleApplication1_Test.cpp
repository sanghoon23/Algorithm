#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int N = 0, M = 0, K = 0;
long long Comb[201][201] = { 0, };
int main()
{
	cin >> N >> M >> K;

	Comb[0][0] = 1;
	for (int j = 1; j <= N + M; ++j)
	{
		Comb[j][0] = 1;
		for (int i = 1; i <= N + M; ++i)
		{
			if (j == i) { Comb[j][i] = 1; continue; }
			Comb[j][i] = Comb[j - 1][i - 1] + Comb[j - 1][i];
			if (Comb[j][i] > 1000000000) Comb[j][i] = 1000000000;
		}
	}

	--K;
	if (Comb[N + M][M] <= K) { cout << -1; return 0; }

	for (int j = N + M - 1; j >= 0; --j)
	{
		if (M >= 0 && Comb[j][M] > K)
			cout << 'a';
		else
		{
			cout << 'z';
			K -= Comb[j][M];
			--M;
		}
	}

	return 0;
}


