#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 100001
int N = 0, K = 0;
int Dp[200002] = { 0, };
int main()
{
	fill(Dp, Dp + 200002, MAX);
	cin >> N >> K;
	vector<int> Value(N);
	for (int i = 0; i < N; ++i)
		cin >> Value[i];

	Dp[0] = 0;
	for (int j = 0; j <= K; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			Dp[j + Value[i]] = min(Dp[j + Value[i]], Dp[j] + 1);
		}
	}
	if (Dp[K] == MAX) cout << -1;
	else cout << Dp[K];
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//@ 안되는 코드
//최소를 구한다면 MAX 를 집어넣고 min 한줄로 찾자.
//최대를 구한다면 MIN 을 집어넣고 max 한줄로 찾자.
//

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int N = 0, K = 0;
//int Dp[200002] = { 0, };
//int main()
//{
//	fill(Dp, Dp + 200002, 0);
//	cin >> N >> K;
//	vector<int> Value(N);
//	for (int i = 0; i < N; ++i)
//		cin >> Value[i];
//
//	for (int j = 0; j <= K; ++j)
//	{
//		for (int i = 0; i < N; ++i)
//		{
//			if (Dp[j + Value[i]] == 0) Dp[j + Value[i]] = Dp[j] + 1;
//			else Dp[j + Value[i]] = min(Dp[j + Value[i]], Dp[j] + 1);
//		}
//	}
//	if (Dp[K]) cout << Dp[K];
//	else cout << -1;
//	return 0;
//}
