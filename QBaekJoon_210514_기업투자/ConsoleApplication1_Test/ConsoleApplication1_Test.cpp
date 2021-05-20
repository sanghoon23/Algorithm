#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, M, Board[21][301], Dp[21][301], Sav[21][301];
int main()
{
	FASTIO;
	cin >> N >> M;
	for (int j = 1; j <= N; ++j)
	{
		int Num; cin >> Num;
		for (int i = 1; i <= M; ++i)
		{
			cin >> Board[i][j];
		}
	}

	for (int j = 1; j <= M; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int k = 0; k <= i; ++k)
			{
				//Dp[j][i] = max(Dp[j][i], Dp[j - 1][i - k] + Board[j][k]);
				if (Dp[j][i] < Dp[j - 1][i - k] + Board[j][k])
				{
					Sav[j][i] = k;
					Dp[j][i] = Dp[j - 1][i - k] + Board[j][k];
				}
			}
		}
	}

	cout << Dp[M][N] << '\n';
	int Calc = N;
	vector<int> Ans;
	for (int j = M; j > 0; --j)
	{
		Ans.push_back(Sav[j][Calc]);
		Calc -= Sav[j][Calc];
	}
	reverse(Ans.begin(), Ans.end());
	for (int i = 0; i < Ans.size(); ++i) cout << Ans[i] << " ";
	return 0;
}

