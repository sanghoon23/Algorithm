#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;
int A = 0, B = 0, C = 0, Dp[21][21][21];
int Solve(int AA, int BB, int CC)
{
	if (AA <= 0 || BB <= 0 || CC <= 0) return 1;
	if (AA > 20 || BB > 20 || CC > 20) return Solve(20, 20, 20);

	int& Ret = Dp[AA][BB][CC];
	if (Ret != 0) return Ret;
	if (AA < BB && BB < CC) Ret += Solve(AA, BB, CC - 1) + Solve(AA, BB - 1, CC - 1) - Solve(AA, BB - 1, CC);
	else Ret += Solve(AA - 1, BB, CC) + Solve(AA - 1, BB - 1, CC) + Solve(AA - 1, BB, CC - 1) - Solve(AA - 1, BB - 1, CC - 1);
	return Ret;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while (1)
	{
		cin >> A >> B >> C;
		if (A == -1 && B == -1 && C == -1) break;
		//cout << "w(" << A <<  ", " << B << ", " << C <<  ") = " << Solve(A, B, C) << '\n';
		printf("w(%d, %d, %d) = %d\n", A, B, C, Solve(A, B, C));
	}
	return 0;
}

