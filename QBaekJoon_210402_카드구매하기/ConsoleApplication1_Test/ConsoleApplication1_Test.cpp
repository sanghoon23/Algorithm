#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, Dp[1001];
int main()
{
	FASTIO;
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> Dp[i];

	for (int j = 1; j <= N; ++j)
		for (int k = 1; j - k > 0; ++k)
			Dp[j] = max(Dp[j], Dp[j - k] + Dp[k]);

	cout << Dp[N];
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////

//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define MMAX 987654321
//int N, Dp[1001][1001], Cost[1001];
//
//int Solve(int Cnt, int K)
//{
//	if (K > N || Cnt > N) return -MMAX;
//
//	int& Ret = Dp[Cnt][K];
//	if (Ret != -1) return Ret;
//	Ret = 0;
//	for (int i = 1; i <= N; ++i)
//		Ret = max(Ret, Solve(Cnt + i, K + 1) + Cost[i]);
//
//	return Ret;
//}
//
//int main()
//{
//	FASTIO;
//	memset(Dp, -1, sizeof(Dp));
//	cin >> N;
//	for (int i = 1; i <= N; ++i) cin >> Cost[i];
//
//	cout << Solve(0, 0);
//	return 0;
//}

