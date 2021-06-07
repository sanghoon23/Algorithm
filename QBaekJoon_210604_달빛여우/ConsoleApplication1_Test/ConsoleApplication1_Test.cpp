#include "pch.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMAX 2e9
#define LL long long
#define PII pair<int ,int>

int N, M;
vector<pair<LL, int>> Board[4001];

int main()
{
	FASTIO;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		LL F, S, W; cin >> F >> S >> W;
		Board[F].push_back({ W, S });
		Board[S].push_back({ W, F });
	}

	vector<LL> Dist_F(N + 1, MMAX);
	Dist_F[1] = 0;
	priority_queue<pair<LL, PII>> PQ; //Cost, Idx, Seq
	PQ.push({ 0, {1, 0} });
	while (!PQ.empty())
	{
		LL Cost = -(PQ.top().first);
		int Idx = PQ.top().second.first;
		PQ.pop();

		if (Dist_F[Idx] < Cost) continue; /* 이 부분을 넣어주어야 하는 이유는?? */

		for (int i = 0; i < Board[Idx].size(); ++i)
		{
			LL NC = Cost + (Board[Idx][i].first) * 2;
			int NextIdx = Board[Idx][i].second;
			if (Dist_F[NextIdx] > NC)
			{
				Dist_F[NextIdx] = NC;
				PQ.push({ -NC, {NextIdx, 0} });
			}
		}
	}

	vector<vector<LL>> Dist_S(N + 1, vector<LL>(2, MMAX));
	//Dist_S[1][0] = 0, Dist_S[1][1] = 0;

	priority_queue< pair<LL, PII> > TPQ; //Cost, Idx, Seq
	TPQ.push({ 0, {1, 0} });
	while (!TPQ.empty())
	{
		LL Cost = -(TPQ.top().first);
		int Idx = TPQ.top().second.first, Seq = TPQ.top().second.second;
		TPQ.pop();

		if (Dist_S[Idx][Seq] < Cost) continue; /* 이 부분을 넣어주어야 하는 이유는?? */

		for (int i = 0; i < Board[Idx].size(); ++i)
		{
			LL NC = Cost, NextIdx = Board[Idx][i].second;
			(Seq == 0) ? NC += Board[Idx][i].first : NC += (Board[Idx][i].first * 4);
			if (Dist_S[NextIdx][!Seq] > NC)
			{
				Dist_S[NextIdx][!Seq] = NC;
				TPQ.push({ -NC, {NextIdx, !Seq} });
			}
		}
	}

	int Result = 0;
	for (int i = 2; i <= N; ++i)
	{
		if (Dist_F[i] < Dist_S[i][0] && Dist_F[i] < Dist_S[i][1]) ++Result;
	}
	cout << Result << '\n';
	return 0;
}

