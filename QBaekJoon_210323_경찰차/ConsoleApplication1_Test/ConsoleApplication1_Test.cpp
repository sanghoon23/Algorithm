#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMAX 987654321
#define PII pair<int, int>
PII Pos[1011];
int N, W, Dp[1011][1011], Form[1011][1011];
int Calc(int A, int B) { return abs(Pos[B].first - Pos[A].first) + abs(Pos[B].second - Pos[A].second); }
int Solve(int Y, int X, int Here)
{
	if (Here - 1 > W) return 0;

	int& Ret = Dp[Y][X];
	if (Ret != -1) return Ret;
	Ret = MMAX;
	int Fir = Solve(Here, X, Here + 1) + Calc(Y, Here);
	int Sec = Solve(Y, Here, Here + 1) + Calc(X, Here);

	if(Fir < Sec) Form[Y][X] = 1;
	return Ret = min(Fir, Sec);
}

void PrintVal(int Y, int X, int Here)
{
	if (Here - 1 > W) return;
	if (Form[Y][X])
	{
		cout << "1" << '\n';
		PrintVal(Here, X, Here + 1);
	}
	else
	{
		cout << "2" << '\n';
		PrintVal(Y, Here, Here + 1);
	}
}

int main()
{
	FASTIO;
	memset(Dp, -1, sizeof(Dp));
	cin >> N >> W;
	Pos[0] = { 1, 1 }; Pos[1] = { N, N };
	for (int i = 2; i <= W + 1; ++i)
		cin >> Pos[i].first >> Pos[i].second;

	cout << Solve(0, 1, 2) << '\n';
	PrintVal(0, 1, 2);
	return 0;
}

