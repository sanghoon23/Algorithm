#include "pch.h"
#include <iostream>
using namespace std;
#define MOD 10007
long long N = 0, K = 0, Combi[1001][1001];
long long Comb(long long Y, long long X)
{
	long long& Ret = Combi[Y][X];
	if (Ret) return Ret;
	if (Y == X || X == 0) return Ret = 1;
	return Ret = (Comb(Y - 1, X - 1) + Comb(Y - 1, X)) % MOD;
}
int main()
{
	cin >> N >> K;
	cout << Comb(N, K) << '\n';
	return 0;
}

