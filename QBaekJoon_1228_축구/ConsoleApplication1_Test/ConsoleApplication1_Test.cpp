#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;
double A = 0.0, B = 0.0, Dp[19][19][19];
bool Prime(int V)
{
	if (V < 2) return false;
	for (int i = 2; i <= (V / 2); ++i)
		if (V % i == 0) return false;
	return true;
}

double Solve(int AA, int BB, int Count, double Val)
{
	if (Count > 18) return 0.0;
	if (Count == 18)
	{
		if (Prime(AA) || Prime(BB)) return Val;
		return 0.0;
	}

	double& Ret = Dp[Count][AA][BB];
	if (Ret > -0.5) return Ret;
	
	Ret = 0.0;
	Ret += Solve(AA, BB, Count + 1, Val * (1 - A) * (1 - B));
	Ret += Solve(AA + 1, BB, Count + 1, Val * A * (1 - B));
	Ret += Solve(AA, BB + 1, Count + 1, Val * (1 - A) * B);
	Ret += Solve(AA + 1, BB + 1, Count + 1, Val * A * B);
	return Ret;
}
int main()
{
	memset(Dp, -1, sizeof(Dp));
	cin >> A >> B;
	A *= 0.01;
	B *= 0.01;

	cout.precision(7);
	cout << Solve(0, 0, 0, 1.0);
	return 0;
}

