#include "pch.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

#define MOD 1000000
string Input = "";
int Dp[5001];
void Solve(int Idx)
{
	if (Idx > Input.size()) return;

	char A = Input[Idx - 2], B = Input[Idx - 1];
	if (A == '0' && B == '0') { cout << 0; exit(0); return; }
	if (B != '0')
	{
		Dp[Idx] += Dp[Idx - 1];
	}
	if (A != '0')
	{
		int Calc = ((A - '0') * 10) + (B - '0');
		if (Calc >= 1 && Calc <= 26)
		{
			Dp[Idx] += Dp[Idx - 2];
		}
	}
	Dp[Idx] %= MOD;
	Solve(Idx + 1);
	return;
}

int main()
{
	memset(Dp, 0, sizeof(Dp));
	cin >> Input;
	if (Input[0] == '0') { cout << 0; return 0; }

	Dp[0] = Dp[1] = 1;
	Solve(2);
	cout << Dp[Input.size()];
	return 0;
}


//#define MOD 1000000
//string Input = "";
//int Dp[5001];
//void Solve(int Idx)
//{
//	if (Idx > Input.size()) return;
//
//	char A = Input[Idx - 2], B = Input[Idx - 1];
//	if (A == '0' && B == '0') { cout << 0; exit(0); return; }
//	if (B != '0')
//	{
//		Dp[Idx] += Dp[Idx - 1];
//	}
//	if (A != '0')
//	{
//		int Calc = ((A - '0') * 10) + (B - '0');
//		if (Calc >= 1 && Calc <= 26)
//		{
//			Dp[Idx] += Dp[Idx - 2];
//		}
//	}
//	Dp[Idx] %= MOD;
//	Solve(Idx + 1);
//	return;
//}
//
//int main()
//{
//	memset(Dp, 0, sizeof(Dp));
//	cin >> Input;
//	if (Input[0] == '0') { cout << 0; return 0; }
//
//	Dp[0] = Dp[1] = 1;
//	Solve(2);
//	cout << Dp[Input.size()];
//	return 0;
//}

