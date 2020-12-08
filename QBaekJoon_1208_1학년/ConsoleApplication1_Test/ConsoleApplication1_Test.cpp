#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
int N = 0, TotalCalc = 0;
int Number[102] = { 0, };
long long Dp[102][21] = { 0, };
void Solve(int Index)
{
	Dp[1][Number[Index]] = 1;
	for (int j = 2; j <= N - 1; ++j)
	{
		for (int i = 0; i <= 20; ++i)
		{
			if (Dp[j - 1][i] == 0) continue;

			if (i + Number[j] <= 20 && i + Number[j] >= 0) Dp[j][i + Number[j]] += Dp[j - 1][i];
			if (i - Number[j] <= 20 && i - Number[j] >= 0) Dp[j][i - Number[j]] += Dp[j - 1][i];
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N - 1; ++i)
	{ cin >> Number[i]; }
	cin >> TotalCalc;

	Solve(1);
	cout << Dp[N - 1][TotalCalc];
	return 0;
}

