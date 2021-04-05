#include "pch.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
string Duru, Board[2];
int Dp[51][101][2];
int Solve(int Z, int Y, bool bBridge)
{
	if (Z >= Duru.size()) return 1;
	int& Ret = Dp[Z][Y][bBridge];
	if (Ret != -1) return Ret;
	Ret = 0;
	for (int k = Y; k < Board[0].size(); ++k)
		if (Duru[Z] == Board[!bBridge][k]) Ret += Solve(Z + 1, k + 1, !bBridge);

	return Ret;
}

int main()
{
	FASTIO;
	memset(Dp, -1, sizeof(Dp));
	cin >> Duru >> Board[0] >> Board[1];
	cout << Solve(0, 0, true) + Solve(0, 0, false);
	return 0;
}

