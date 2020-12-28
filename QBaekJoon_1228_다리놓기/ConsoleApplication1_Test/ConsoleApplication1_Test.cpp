#include "pch.h"
#include <iostream>
using namespace std;
int T = 0;
long long N = 0, M = 0, Combi[31][31];
long long Combination(long long Y, long long X)
{
	if (X > Y) swap(X, Y);
	long long& Ret = Combi[Y][X];
	if (Ret != 0) return Ret;
	//if (X == 1) return Ret = Y;
	//if (Y == X) return Ret = 1;
	if (X == 0 || Y == X) return Ret = 1;
	return Ret = Combination(Y - 1, X - 1) + Combination(Y - 1, X);
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		cout << Combination(N, M) << '\n'; //@N 부터 들어간다..swap() 실행..
	}
	return 0;
}

