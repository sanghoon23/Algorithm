#include "pch.h"
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
string A, B;
int Dp[1001][1001];
int main()
{
	memset(Dp, 0, sizeof(Dp));
	cin >> A >> B;
	for (int j = 1; j <= A.size(); ++j)
	{
		for (int i = 1; i <= B.size(); ++i)
		{
			if (A[j - 1] == B[i - 1]) Dp[j][i] = Dp[j - 1][i - 1] + 1;
			else Dp[j][i] = max(Dp[j - 1][i], Dp[j][i - 1]);
		}
	}

	string Result;
	int Y = A.size(), X = B.size();
	while (Y > 0 && X > 0)
	{
		if (Dp[Y][X] == Dp[Y][X - 1]) --X;
		else if (Dp[Y][X] == Dp[Y - 1][X]) --Y;
		else
		{
			Result.push_back(A[Y - 1]);
			--Y; --X;
		}
	}
	cout << Result.size();
	return 0;
}

