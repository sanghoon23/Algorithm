#include "pch.h"
#include <iostream>
using namespace std;
int N = 0, K = 0, Combi[12][12];
int Comb(int Y, int X)
{
	int& Ret = Combi[Y][X];
	if (Ret) return Ret;
	if (Y == X || X == 0) return Ret = 1;
	return Ret = Comb(Y - 1, X - 1) + Comb(Y - 1, X);
}
int main()
{
	cin >> N >> K;
	cout << Comb(N, K) << '\n';
	return 0;
}

