#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PII pair<int, int>
#define MSIZE 10001
int N, Cost[MSIZE], InDegree[MSIZE];
vector<int> Board[MSIZE];
int main()
{
	FASTIO;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Cost[i];
		int Num; cin >> Num;
		for (int k = 0; k < Num; ++k)
		{
			int Input; cin >> Input;
			Board[i].push_back(Input);
			++InDegree[Input];
		}
	}

	vector<int> Dist(N + 1);
	queue<PII> Que;
	for (int i = 1; i <= N; ++i)
		if (InDegree[i] == 0)
		{
			Dist[i] = Cost[i];
			Que.push({ Cost[i], i });
		}

	while (!Que.empty())
	{
		int C = Que.front().first, Idx = Que.front().second;
		Que.pop();

		for (int Next : Board[Idx])
		{
			Dist[Next] = max(Dist[Next], C + Cost[Next]);
			if (--InDegree[Next] == 0)
				Que.push({ Dist[Next], Next });
		}
	}
	int Answer = 0;
	for (int i = 1; i <= N; ++i)
		Answer = max(Answer, Dist[i]);
	cout << Answer;
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//@DP 방법
//int Solve(int Idx)
//{
//	int& Ret = Dp[Idx];
//	if (Ret != -1) return Ret;
//
//	Ret = Cost[Idx];
//	int MMax = 0;
//	for (int Next : Board[Idx])
//		MMax = max(MMax, Solve(Next));
//
//	return Ret += MMax;
//}
//
//int main()
//{
//	FASTIO;
//	memset(Dp, -1, sizeof(Dp));
//	cin >> N;
//	for (int i = 1; i <= N; ++i)
//	{
//		cin >> Cost[i];
//		int Num; cin >> Num;
//		for (int k = 0; k < Num; ++k)
//		{
//			int Input; cin >> Input;
//			Board[i].push_back(Input);
//		}
//	}
//	for (int i = 1; i <= N; ++i) if (Dp[i] == -1) Solve(i);
//	int Answer = 0;
//	for (int i = 1; i <= N; ++i) Answer = max(Answer, Dp[i]);
//	cout << Answer;
//	return 0;
//}

