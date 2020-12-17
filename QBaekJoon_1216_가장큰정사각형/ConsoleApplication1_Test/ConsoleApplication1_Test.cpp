#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

/*
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (arr[i][j] == '1')
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				res = max(res, dp[i][j]);
			}

*/
//시간을 줄이기 위해 51번째 줄 for 문을 줄여서 Solve(0, 0) 한번의 호출로 찾아보려했는데,
//정사각형의 값 1 을 찾아야되기 때문에, 51번째줄 이중 for문은 필요하다.
//따라서, 현재 재귀의 Dp를 for문의 Dp 로 바꾸기 위해선 이중 for 문안에 Dp 점화식을 세워야 함.

using namespace std;
int N = 0, M = 0, Board[1001][1001], Dp[1001][1001];
int Solve(int Y, int X)
{
	if (Y < 0 || Y >= N || X < 0 || X >= M) return 0;
	if (Board[Y][X] == 0) return 0;

	int& Ret = Dp[Y][X];
	if (Ret != -1) return Ret;
	Ret = 1;

	int A = Solve(Y + 1, X), B = Solve(Y, X + 1), C = Solve(Y + 1, X + 1);
	if (A != 0 && B != 0 && C != 0) { Ret = min(A, min(B, C)) + 1; }
	return Ret;
}

int main()
{
	cin >> N >> M;
	memset(Dp, -1, sizeof(Dp));
	memset(Board, 0, sizeof(Board));
	for (int j = 0; j < N; ++j)
	{
		string Input = "";
		cin >> Input;
		for (int i = 0; i < M; ++i)
		{
			Board[j][i] = Input[i] - '0';
		}
	}

	int Answer = 0;
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < M; ++i)
			Answer = max(Answer, Solve(j, i));

	cout << Answer * Answer;
	return 0;
}

