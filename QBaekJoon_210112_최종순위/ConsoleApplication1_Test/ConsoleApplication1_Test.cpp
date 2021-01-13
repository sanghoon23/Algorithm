#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int T = 0, N = 0, K = 0;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int> Input(N + 1);
		for (int i = 1; i <= N; ++i)
			cin >> Input[i];

		vector<vector<int>> Board(N + 1, vector<int>(N + 1));
		for (int j = 1; j <= N; ++j)
			for (int i = j + 1; i <= N; ++i)
				Board[Input[j]][Input[i]] = 1;

		cin >> K;
		for (int i = 0; i < K; ++i)
		{
			int F, S;
			cin >> F >> S;
			swap(Board[F][S], Board[S][F]);
		}

		for (int j = 1; j <= N; ++j)
			for (int i = j + 1; i <= N; ++i)
				if (Board[Input[i]][Input[j]] == 1) swap(Input[i], Input[j]);

		bool bImpossible = false;
		for (int j = 1; j <= N; ++j)
			for (int i = j + 1; i <= N; ++i)
				if (Board[Input[i]][Input[j]] == 1) { bImpossible = true; }

		if (bImpossible == true) printf("IMPOSSIBLE");
		else
		{
			for (int k = 1; k <= N; ++k)
				printf("%d ", Input[k]);
		}
		printf("\n");
	}
	return 0;
}

