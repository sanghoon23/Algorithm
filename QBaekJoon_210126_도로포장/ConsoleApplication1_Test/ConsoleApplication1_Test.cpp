#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define LL long long
#define PII pair<int, int>
#define MMAX 10000000001
#define NSIZE 10001
int N, M, K;
vector<PII> Board[NSIZE];

LL Dikjstra(int Start)
{
	vector<vector<LL>> Dp(N + 1, vector<LL>(K + 1, MMAX));
	Dp[Start][0] = 0;
	priority_queue<pair<LL, PII>> PQ;
	PQ.push({ 0, {Start, 0} }); //@비용, 인덱스, K
	while (!PQ.empty())
	{
		LL Cost = -(PQ.top().first);
		int Idx = PQ.top().second.first, KVal = PQ.top().second.second;
		PQ.pop();

		//@아래의 조건 (Dp[Idx][KVal] < Cost) continue;) 를 넣어줄 필요가 있나?? - 
		/*
		여러 개의 값들이 우선순위 큐에 들어오고,
		값이 작은거 부터 Pop하면서 DP 값이 갱신된다.
		그로 인해 "이미 우선순위큐에 들어온 값" 들이 조건에 만족하지 않은 값들일 수 있다..
		따라서, 아래 조건을 넣어줘야 예외가 발생치 않는다.
		*/
		if (Dp[Idx][KVal] < Cost) continue;

		for (PII Next : Board[Idx])
		{
			int NextIdx = Next.first;
			LL NC = (LL)(Next.second);
			if (Dp[NextIdx][KVal] > NC + Cost)
			{
				Dp[NextIdx][KVal] = NC + Cost;
				PQ.push({ -(NC + Cost), {NextIdx, KVal} });
			}
			int NextKK = KVal + 1;
			if (NextKK <= K && Dp[NextIdx][NextKK] > Cost)
			{
				Dp[NextIdx][NextKK] = Cost;
				PQ.push({ -(Cost), {NextIdx, NextKK} });
			}
		}
	}

	LL Ret = MMAX;
	for (int i = 0; i <= K; ++i)
		Ret = min(Ret, Dp[N][i]);

	return Ret;
}

int main()
{
	FASTIO;
	cin >> N >> M >> K;
	for (int i = 0; i < M; ++i)
	{
		int F, S, W;
		cin >> F >> S >> W;
		Board[F].push_back({ S, W });
		Board[S].push_back({ F, W });
	}
	cout << Dikjstra(1) << '\n';
	return 0;
}

