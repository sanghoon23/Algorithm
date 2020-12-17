#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
int N = 0, Line[501], Dp[501], MM = 0;//@MM - Max 값
int Solve(int Idx)
{
	if (Idx > MM) return 0;
	if (Line[Idx] == 0) return 0;

	int& Ret = Dp[Idx];
	if (Ret != -1) return Ret;

	Ret = 1;
	for (int i = Idx + 1; i <= MM; ++i)
	{
		if (Line[i] > Line[Idx])
		{
			Ret = max(Ret, Solve(i) + 1);
		}
	}
	return Ret;
}
int main()
{
	memset(Dp, -1, sizeof(Dp));
	memset(Line, 0, sizeof(Line));
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int F = 0, S = 0;
		cin >> F >> S;
		Line[F] = S;
		MM = max(MM, max(F, S));
	}

	int Result = 0;
	for (int i = 1; i <= MM; ++i)
		Result = max(Result, Solve(i));

	cout << N - Result;
	return 0;
}

