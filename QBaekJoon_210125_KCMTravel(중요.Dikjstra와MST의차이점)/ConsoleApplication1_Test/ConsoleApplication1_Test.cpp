#include "pch.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@DP 이용 결과 - 시간 너무 오래 걸림, Idx == N 으로 처리
//왜?? - 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PII pair<int, int>
#define MMAX 100001
#define MSIZE 101
int T, N, M, K;
vector<pair<int, PII>> Board[MSIZE];

void Dikjstra(int Start)
{
	vector<vector<int>> Time(MSIZE, vector<int>(10001, MMAX));
	fill(Time[Start].begin(), Time[Start].end(), 0);

	priority_queue<pair<int, PII>> PQ;
	PQ.push({ 0, {0, Start} }); //@소요시간, 비용, 정점
	while (!PQ.empty())
	{
		int TimeRate = -(PQ.top().first), Cost = PQ.top().second.first, Idx = PQ.top().second.second;
		PQ.pop();

		if (TimeRate != Time[Idx][Cost]) continue;
		if (Idx == N)
		{
			cout << TimeRate << '\n';
			return;
		}

		for (pair<int, PII> Next : Board[Idx])
		{
			int NC = Next.second.first, NT = Next.second.second, NextIdx = Next.first;
			if (NC + Cost > M) continue;
			if (Time[NextIdx][NC + Cost] > TimeRate + NT)
			{
				for (int i = NC + Cost; i <= M; ++i)
				{
					if(Time[NextIdx][i] > TimeRate + NT) Time[NextIdx][i] = TimeRate + NT;
					else break;
				}

				PQ.push({ -(TimeRate + NT), {(NC + Cost), NextIdx } });
			}
		}
	}
	cout << "Poor KCM" << '\n';
}

int main()
{
	FASTIO;
	cin >> T;
	while (T--)
	{
		cin >> N >> M >> K;
		for (int i = 0; i <= N; ++i) Board[i].clear();

		for (int i = 0; i < K; ++i)
		{
			int U, V, C, D;
			cin >> U >> V >> C >> D;
			Board[U].push_back({ V, {C, D} });
		}
		Dikjstra(1);
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@삽질
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define PII pair<int, int>
//#define MMAX 100001
//#define MSIZE 101
//int T, N, M, K;
//vector<pair<int, PII>> Board[MSIZE];
//
//void Dikjstra(int Start)
//{
//	vector<int> Time(N + 1, MMAX);
//
//	priority_queue<pair<int, PII>> PQ;
//	PQ.push({ 0, {0, Start} }); //@소요시간, 비용, 정점
//	while (!PQ.empty())
//	{
//		int TimeRate = -(PQ.top().first), Cost = PQ.top().second.first, Idx = PQ.top().second.second;
//		PQ.pop();
//
//		if (Idx == N) break;
//
//		for (pair<int, PII> Next : Board[Idx])
//		{
//			int NC = Cost + Next.second.first, NT = TimeRate + Next.second.second, NextIdx = Next.first;
//			if (M >= NC && Time[NextIdx] > NT)
//			{
//				Time[NextIdx] = NT;
//				PQ.push({ -NT, {NC, NextIdx} });
//			}
//		}
//	}
//
//	if (Time[N] >= MMAX) cout << "Poor KCM" << '\n';
//	else cout << Time[N] << '\n';
//}
//
//int main()
//{
//	FASTIO;
//	cin >> T;
//	while (T--)
//	{
//		cin >> N >> M >> K;
//		for (int i = 0; i <= N; ++i) Board[i].clear();
//
//		for (int i = 0; i < K; ++i)
//		{
//			int U, V, C, D;
//			cin >> U >> V >> C >> D;
//			Board[U].push_back({ V, {C, D} });
//		}
//		Dikjstra(1);
//	}
//	return 0;
//}


