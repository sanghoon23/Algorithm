#include "pch.h"
#include <iostream>

using namespace std;
//long long T = 0, X = 0, Y = 0, Dp[1000001];
//int main()
//{
//	Dp[1] = 1;
//	for (int i = 2; i <= 100000; ++i)
//		Dp[i] = Dp[i - 1] + 2;
//
//	cin >> T;
//	while (T--)
//	{
//		cin >> X >> Y;
//		long long N = 1;
//		for (N = 1; ; ++N)
//			if (N * N >= Y - X) break;
//
//		if (N*N - (N - 1) <= Y - X) cout << Dp[N] << '\n';
//		else cout << Dp[N] - 1 << '\n';
//	}
//	return 0;
//}

typedef long long ll;

int sol(ll n) {
	ll tmp = 0, ans = 1;
	while (1) {
		tmp += ((ans + 1) >> 1);
		if (tmp >= n)return ans;
		++ans;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		ll x, y; cin >> x >> y;
		cout << sol(y - x) << '\n';
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@문제를 잘못 이해했다..ㅜ
//using namespace std;
//long long T = 0, X = 0, Y = 0;
//int main()
//{
//	cin >> T;
//	while (T--)
//	{
//		cin >> X >> Y;
//		long long Start = 1, End = (Y - X);
//		long long Mid = 0, Sum = 0;
//		long long Answer = 0;
//		while (Start <= End)
//		{
//			Mid = (Start + End) >> 1;
//			Sum = (Mid * (Mid - 1)) / 2;
//			if (X + Sum - 1 <= Y)
//			{
//				Answer = Mid;
//				Start = Mid + 1;
//			}
//			else
//			{
//				End = Mid - 1;
//			}
//		}
//		cout << Answer << '\n';
//	}
//	return 0;
//}

