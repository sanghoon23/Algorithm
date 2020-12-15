#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int N = 0;
string Dp[10001] = { "" };
string Calc(string Str1, string Str2)
{
	reverse(Str1.begin(), Str1.end());
	reverse(Str2.begin(), Str2.end());
	string Ret = "";
	for (int k = 0; k < Str1.size(); ++k)
	{
		int R = 0;
		(k >= Str2.size())
			? R = (Str1[k] - '0')
			: R = (Str1[k] - '0') + (Str2[k] - '0');

		Ret.push_back((R % 10) + '0');
		if (R >= 10)
		{
			if (k == Str1.size() - 1) Ret.push_back('1');
			else Str1[k + 1] = ((Str1[k + 1] - '0') + 1) + '0';
		}
	}
	reverse(Ret.begin(), Ret.end());
	return Ret;
}
int main()
{
	cin >> N;
	Dp[0] = '0';
	Dp[1] = '1';
	for (int i = 2; i <= N; ++i)
		Dp[i] = Calc(Dp[i - 1], Dp[i - 2]);

	cout << Dp[N];
	return 0;
}

