#include "pch.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define LL long long
LL N = 0, Dp[91][2];
LL Solve(int Idx, int Before, string Str)
{
	if (Idx >= N - 1) return 1;

	LL& Ret = Dp[Idx][Before];
	if (Ret != -1) return Ret;
	Ret = 0;
	if (Str[Idx] == '1') Ret += Solve(Idx + 1, 0, Str + "0");
	else if (Str[Idx] == '0')
	{
		Ret += Solve(Idx + 1, 0, Str + "0");
		Ret += Solve(Idx + 1, 1, Str + "1");
	}
	return Ret;
}

int main()
{
	memset(Dp, -1, sizeof(Dp));
	cin >> N;
	string Input = "1";
	cout << Solve(0, 1, Input);

	return 0;
}

