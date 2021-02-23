#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, M, Dp[41], Answer = 1;
int main()
{
	FASTIO;
	cin >> N >> M;
	memset(Dp, 0, sizeof(Dp));
	Dp[0] = 1; Dp[1] = 1;
	for (int i = 2; i <= N; ++i) Dp[i] = Dp[i - 1] + Dp[i - 2];

	int Start = 1;
	for (int i = 0; i < M; ++i)
	{
		int Input; cin >> Input;
		Answer *= Dp[Input - Start];
		Start = Input + 1;
	}
	Answer *= Dp[N - Start + 1];
	cout << Answer;
	return 0;
}

