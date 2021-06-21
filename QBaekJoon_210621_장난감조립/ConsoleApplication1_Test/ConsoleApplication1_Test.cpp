#include "pch.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PII pair<int, int>

int N, M, InDegree[101], Cost[101];
vector<PII> Board[101];

int main()
{
	FASTIO;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int F, S, W; cin >> W >> F >> S;
		Board[W].push_back({ F, S });
		++InDegree[F];
	}

	queue<int> Que;
	Que.push(N);
	Cost[N] = 1;
	while (!Que.empty())
	{
		int Idx = Que.front(); Que.pop();

		for (int i = 0; i < Board[Idx].size(); ++i)
		{
			int NI = Board[Idx][i].first, NC = Board[Idx][i].second;
			Cost[NI] += NC * Cost[Idx];
			if(--InDegree[NI] == 0) Que.push(NI);
		}
	}

	for (int i = 1; i < N; ++i)
	{
		if (Board[i].empty()) cout << i << " " << Cost[i] << '\n';
	}
	return 0;
}



/*
@삽질
무엇이 나를 힘들게 했는가...
왜 PII 컨테이너 Que 를 잡은거지??
*/


//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define PII pair<int, int>
//
//int N, M, InDegree[101], Cost[101];
//vector<PII> Board[101];
//
//int main()
//{
//	FASTIO;
//	cin >> N >> M;
//	for (int i = 0; i < M; ++i)
//	{
//		int F, S, W; cin >> W >> F >> S;
//		Board[W].push_back({ F, S });
//	}
//	Cost[N] = 1;
//
//	for (int j = N; j > 0; --j)
//	{
//		sort(Board[j].begin(), Board[j].end());
//		for (int i = 0; i < Board[j].size(); ++i)
//		{
//			int Idx = Board[j][i].first, Cnt = Board[j][i].second;
//			Cost[Idx] += Cost[j] * Cnt;
//		}
//	}
//
//	//queue<PII> Que;
//	//Que.push({ N, 1 });
//	//while (!Que.empty())
//	//{
//	//	int Idx = Que.front().first, Cnt = Que.front().second;
//	//	Que.pop();
//
//	//	for (int i = 0; i < Board[Idx].size(); ++i)
//	//	{
//	//		int NI = Board[Idx][i].first, NC = Board[Idx][i].second;
//	//		Cost[NI] += NC * Cnt;
//	//		Que.push({ NI, NC * Cnt });
//	//	}
//	//}
//
//	for (int i = 1; i <= N; ++i)
//	{
//		if (Board[i].empty()) cout << i << " " << Cost[i] << '\n';
//		else break;
//	}
//	return 0;
//}

