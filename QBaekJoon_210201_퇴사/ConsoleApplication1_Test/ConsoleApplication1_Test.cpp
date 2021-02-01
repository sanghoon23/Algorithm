#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

/*
//@미친 코드
int main()
{
	int n,t,f;
	int DP[20]={}, fit[20]={};
	scanf("%d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		scanf("%d %d",&t,&f);
		DP[i-1+t] = max(DP[i-1+t],DP[i-1]+f);
		DP[i] = max(DP[i],DP[i-1]);
	}
	printf("%d",DP[n]);
}
*/
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 16
int N, Dp[MSIZE][2], Time[MSIZE], Cost[MSIZE];
int Solve(int Idx, int Sel)
{
	if (Idx > N) return 0;
	int& Ret = Dp[Idx][Sel];
	if (Ret != -1) return Ret;
	Ret = 0;
	if (Sel == 0) Ret = max(Solve(Idx + 1, 1), Solve(Idx + 1, 0));
	else if (Sel == 1)
	{
		if (Idx + Time[Idx] - 1 <= N)
		{
			Ret = Cost[Idx];
			Ret += max(Solve(Idx + Time[Idx], 1), Solve(Idx + Time[Idx], 0));
		}
	}
	return Ret;
}

int main()
{
	FASTIO;
	cin >> N;
	memset(Dp, -1, sizeof(Dp));
	for (int i = 1; i <= N; ++i)
	{
		cin >> Time[i];
		cin >> Cost[i];
	}
	cout << max(Solve(1, 0), Solve(1, 1)) << '\n';
	return 0;
}

