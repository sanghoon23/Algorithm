#include "pch.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, Dp[100001];
int main()
{
	FASTIO;
	cin >> N;
	Dp[1] = 1; Dp[2] = 2; Dp[3] = 3;
	for (int j = 4; j <= N; ++j)
	{
		int Sq = (int)(sqrt(j));
		for (int i = Sq; i >= 1; --i)
		{
			int Ss = i * i;
			if(Dp[j] == 0) Dp[j] = Dp[j - Ss] + 1;
			else Dp[j] = min(Dp[j], Dp[j - Ss] + 1);
		}
	}
	cout << Dp[N];
	return 0;
}

