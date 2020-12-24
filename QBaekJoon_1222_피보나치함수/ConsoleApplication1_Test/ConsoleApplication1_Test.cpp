#include "pch.h"
#include <iostream>

using namespace std;
int T = 0, N = 0;
pair<int, int> Dp[50] = { {1, 0}, {0, 1},};
int main()
{
	cin >> T;
	for (int i = 2; i <= 42; ++i)
		Dp[i] = { (Dp[i - 1].first) + (Dp[i - 2].first) , (Dp[i - 1].second) + (Dp[i - 2].second) };

	for (int u = 0; u < T; ++u)
	{
		cin >> N;
		printf("%d %d\n", Dp[N].first, Dp[N].second);
	}
	return 0;
}

//
//int Fibo(int N)
//{
//	if (N == 0) {
//		printf("0");
//		return 0;
//	}
//	else if (N == 1) {
//		printf("1");
//		return 1;
//	}
//	return Fibo(N - 1) + Fibo(N - 2);
//}
