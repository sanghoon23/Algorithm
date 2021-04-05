#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define LL long long
LL N, L, R, Dp[101][101][101];
int main()
{
	FASTIO;
	cin >> N >> L >> R;
	Dp[1][1][1] = 1;

	for (int k = 2; k <= N; ++k)
		for (int j = 1; j <= k; ++j)
			for (int i = 1; i <= k; ++i)
			{
				Dp[k][j][i] = (Dp[k - 1][j][i - 1] + Dp[k - 1][j - 1][i] + (Dp[k - 1][j][i] * (k - 2) % MOD)) % MOD;
				Dp[k][j][i] %= MOD;
			}

	cout << Dp[N][L][R];
	return 0;
}






//////////////////////////////////////////////////////////////////////////////
//@삽질

//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define MOD 1000000007
//int N, L, R, Dp[101][101][101];
//int main()
//{
//	FASTIO;
//	cin >> N >> L >> R;
//	Dp[1][1][0] = Dp[1][0][1] = Dp[1][1][1] = 1;
//	for (int k = 2; k <= N; ++k)
//		for (int j = 1; j <= k; ++j)
//			for (int i = 1; i <= k; ++i)
//			{
//
//				Dp[k][j][i] = (Dp[k - 1][j - 1][i] + Dp[k - 1][j][i - 1]) % MOD;
//
//			}
//
//	cout << Dp[N][L][R];
//	return 0;
//}

