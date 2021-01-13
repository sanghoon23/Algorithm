#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
#define MMAX 1000001
#define PII pair<int, int>
int T = 0, N = 0;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<PII> Board(N + 3);
		for (int i = 1; i <= 
			N + 2; ++i)
		{
			int F, S;
			cin >> F >> S;
			Board[i] = {F, S};
		}

		vector<vector<int>> Temp(N + 3, vector<int>(N + 3, MMAX));
		for (int j = 1; j <= N + 2; ++j)
		{
			for (int i = 1; i <= N + 2; ++i)
			{
				
				int R = abs(Board[j].first - Board[i].first) + abs(Board[j].second - Board[i].second);
				if (R > 1000 || i == j) continue;
				Temp[j][i] = 1;
			}
		}

		for (int k = 1; k <= N + 2; ++k)
		{
			for (int j = 1; j <= N + 2; ++j)
			{
				for (int i = 1; i <= N + 2; ++i)
				{
					if (i == j) continue;
					if (Temp[j][i] > Temp[j][k] + Temp[k][i])
						Temp[j][i] = Temp[j][k] + Temp[k][i];
				}
			}
		}

		if (Temp[1][N + 2] > 0 && Temp[1][N + 2] < MMAX) cout << "happy" << '\n';
		else cout << "sad" << '\n';
	}
	return 0;
}

